#include "Arvid.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>
#include "Flower.h"
#include "EntityManager.h"

static const float	MAXRUNSPEED		= 8;
static const float	MAXJUMPSPEED	= 18;
static const int	JUMPTIME		= 30;
static const float	MINFALLSPEED	= 0.1;
static const float	MAXFALLSPEED	= 20;

Arvid::Arvid(sf::Vector2f &position):
	//mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("arvid_idle_right.png", 0, 1),
	mRunLeftAnimation	("arvid_sprint_left2.png", 24, 16),
	mRunRightAnimation	("arvid_sprint_right2.png", 24, 16),
	mJumpRightAnimation	("arvid_jump_right2.png", 24, 9),
	mJumpLeftAnimation	("arvid_jump_left2.png", 24, 9),
	mAirborneLeftAnimation("arvid_airborne_left2.png", 0, 1),
	mAirborneRightAnimation("arvid_airborne_right2.png", 0, 1),
	mMovementSpeed(0,1),
	mRunSpeed(1),
	mJumping(false),
	mFalling(true),
	mJumpDecrease(0.6),
	mFallAcc(0.8),
	mJumpTime(0),
	mLove(100),
	mFlower(NULL),
	mPlanting(false),
	mLoveBarRect(0, 0, 700, 48),
	mCountdown(300)
{ 
	mLayer = FRONT;
	mEntityKind = ARVID;
	setPosition(position);

	mLoveBarTexture.loadFromFile("Hud_meter_love_bar.png");
	mLoveTexture.loadFromFile("HUD_meter_love_heart.png");
	mLoveBarSprite.setTexture(mLoveBarTexture);
	mLoveSprite.setTexture(mLoveTexture);
	mLoveBarSprite.setTextureRect(static_cast<sf::IntRect>(mLoveBarRect));
	mLoveBarSprite.setPosition(80, 0);
	mLoveSprite.setPosition(0, 0);

	mHitBox = sf::FloatRect(position + sf::Vector2f(45, 8), sf::Vector2f(52, 152));

	mCurrentAnimation = &mIdleRightAnimation;
}

Arvid::~Arvid(){ }


void Arvid::update()
{
	move();
	jumping();
	falling();
	updateHUD();
	

	plantFlower();

	if(!mPlanting)
	{
		walk();
		jump();
		fall();

		if(mCurrentAnimation == &mJumpLeftAnimation && mCurrentAnimation->endOfAnimation())
		{
			mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mAirborneLeftAnimation;
		}
		else if(mCurrentAnimation == &mJumpRightAnimation && mCurrentAnimation->endOfAnimation())
		{
			mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mAirborneRightAnimation;
		}
	}
	mCurrentAnimation->update();
}

void Arvid::render(sf::RenderWindow &window)
{
	mIdleRightAnimation.setPosition(getPosition());
	mRunLeftAnimation.setPosition(getPosition());
	mRunRightAnimation.setPosition(getPosition());
	mJumpRightAnimation.setPosition(getPosition());
	mJumpLeftAnimation.setPosition(getPosition());
	mAirborneLeftAnimation.setPosition(getPosition());
	mAirborneRightAnimation.setPosition(getPosition());

	mLoveSprite.setPosition(sf::Vector2f(window.getView().getCenter().x - 940, window.getView().getCenter().y - 520));
	mLoveBarSprite.setPosition(sf::Vector2f(window.getView().getCenter().x - 860, window.getView().getCenter().y - 500));

	mCurrentAnimation->setPosition(getPosition()- sf::Vector2f(45, 8));

	window.draw(mCurrentAnimation->getSprite());
	window.draw(mLoveBarSprite);
	window.draw(mLoveSprite);
}

void Arvid::onCollision(Entity *e, sf::FloatRect &result)
{
	EntityKind kind = e->getEntityKind();

	if(kind == NORMALBLOCK)
		{
		if(result.height > result.width)
		{
			if(result.left > mHitBox.left)
			{
				mHitBox.left -= result.width;
			}
			else
			{
				mHitBox.left += result.width;
			}
		}
		else
		{
			if(result.top > mHitBox.top)
			{
				if(result.width > 10)
				{
					mHitBox.top -= result.height;

					if(mFalling)
					{
						mMovementSpeed.y = MINFALLSPEED;
					}
					mFalling = false;
				}
			}
			else
			{
				if(result.width > 10)
				{
					mHitBox.top += result.height;
					dontJump();
				}
			}
		}
	}
	else if(kind == FLOWER)
	{
		if(mHitBox.top < e->getHitBox().top - 275)
		{
			if(result.width > 10)
			{
				mHitBox.top -= result.height;

				if(mFalling)
				{
					mMovementSpeed.y = MINFALLSPEED;
				}
				mFalling = false;
			}
		}
	}


}

void Arvid::move()
{
	float x = mHitBox.left;
	float y = mHitBox.top;
	setPosition(sf::Vector2f(x += mMovementSpeed.x, y += mMovementSpeed.y));

	if(!mJumping && !mFalling)
	{
		if(mMovementSpeed.x > 0)
		{
			mCurrentAnimation = &mRunRightAnimation;
			mRunLeft = false;
		}
		else if(mMovementSpeed.x < 0)
		{
			mCurrentAnimation = &mRunLeftAnimation;
			mRunLeft = true;
		}
		else
		{
			mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mIdleRightAnimation;
		}
	}

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || mPlanting)
	{
		mMovementSpeed.x = 0;			
	}
}

void Arvid::walk()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && mMovementSpeed.x < MAXRUNSPEED)
	{
		mMovementSpeed.x += mRunSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && mMovementSpeed.x > -MAXRUNSPEED)
	{
		mMovementSpeed.x -= mRunSpeed;
	}
}

void Arvid::jump()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !mJumping && !mFalling)
	{
		mJumping = true;
		mJumpTime = 0;
		mMovementSpeed.y = -MAXJUMPSPEED;
		
		if(mRunLeft == true)
		{
			//mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mJumpLeftAnimation;
		}
		else
		{
			//mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mJumpRightAnimation;
		}
	}
}

void Arvid::dontJump()
{
	mJumpTime = 0;
	mJumping = false;
	mFalling = true;
	mMovementSpeed.y = MINFALLSPEED;
}

void Arvid::jumping()
{
	if(mJumping)
	{
		mMovementSpeed.y += mJumpDecrease;
		
		++mJumpTime;
		
		if(mJumpTime >= JUMPTIME)
		{
			dontJump();
		}
	}
}

void Arvid::fall()
{
	if(!mJumping)
	{
		mFalling = true;
	}
}

void Arvid::falling()
{
	if(mFalling)
	{
		if(mMovementSpeed.y < MAXFALLSPEED)
		{	
			mMovementSpeed.y += mFallAcc;
		}
	}
}

void Arvid::plantFlower()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !mJumping && !mFalling && mLove >= 0)
	{
		mPlanting = true;
		mLove -= 0.5;
		mCountdown = 300;
		if(mFlower == NULL)
		{
			mFlower = new Flower(getPosition() + sf::Vector2f(128, 240));
			EntityManager::getInstance()->addDynamicEntity(mFlower);
		}

		mFlower->grow();
	}
	else
	{
		mPlanting = false;
		if(mLove <= 100 && mCountdown <= 0)
		{
			mLove += 0.25;
		}
		if(mFlower != NULL)
		{
			mFlower->isNotGrowing();
		}

		if(mCountdown > 0)
			--mCountdown;

		mFlower = NULL;
	}
}

void Arvid::updateHUD()
{
	float x = mLove * 7;

	mLoveBarRect.left = mLoveBarRect.width - x;

	mLoveBarSprite.setTextureRect(static_cast<sf::IntRect>(mLoveBarRect));
}
