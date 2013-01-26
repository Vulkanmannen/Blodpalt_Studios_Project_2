#include "Arvid.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>
#include "Flower.h"
#include "EntityManager.h"

static const float	MAXRUNSPEED		= 6;
static const float	MAXJUMPSPEED	= 16;
static const int	JUMPTIME		= 30;
static const float	MINFALLSPEED	= 0.1;
static const float	MAXFALLSPEED	= 20;

Arvid::Arvid(sf::Vector2f &position):
	//mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("arvid_idle_placehold.png", 0, 1),
	mRunLeftAnimation	("arvid_sprint_left.png", 24, 16),
	mRunRightAnimation	("arvid_sprint_right.png", 24, 16),
	mJumpRightAnimation	("arvid_jump_right.png", 24, 9),
	mJumpLeftAnimation	("arvid_jump_left.png", 24, 9),
	mAirborneLeftAnimation("arvid_airborne_left.png", 0, 1),
	mAirborneRightAnimation("arvid_airborne_right.png", 0, 1),
	mMovementSpeed(0,1),
	mRunSpeed(3),
	mJumping(false),
	mFalling(true),
	mJumpDecrease(0.6),
	mFallAcc(0.8),
	mJumpTime(0),
	mLove(100),
	mFlower(NULL)
{ 
	mEntityKind = ARVID;
	setPosition(position);
	mTexture.loadFromFile("GUBBJEVEL.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(position);
	mHitBox = sf::FloatRect(position + sf::Vector2f(113, 32), sf::Vector2f(96, 285));
	mCurrentAnimation = &mIdleRightAnimation;
}

Arvid::~Arvid(){ }


void Arvid::update()
{
	move();
	walk();
	jump();
	jumping();
	fall();
	falling();
	plantFlower();

	mCurrentAnimation->update();


	if(mCurrentAnimation == &mJumpLeftAnimation && mCurrentAnimation->endOfAnimation())
		mCurrentAnimation = &mAirborneLeftAnimation;

	else if(mCurrentAnimation == &mJumpRightAnimation && mCurrentAnimation->endOfAnimation())
		mCurrentAnimation = &mAirborneRightAnimation;

	
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

	mCurrentAnimation->setPosition(getPosition()- sf::Vector2f(113, 32));
	window.draw(mCurrentAnimation->getSprite());
}

void Arvid::onCollision(Entity *e)
{
	float yDif = mHitBox.top - e->getHitBox().top;  

	if(yDif < - 55)
	{
		if(mFalling)
		{
			mMovementSpeed.y = MINFALLSPEED;
		}
		mFalling = false;
	}
	else if(yDif > 55)
	{
		dontJump();
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
	else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mMovementSpeed.x = 0;			
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
			mCurrentAnimation->resetFrameCount();
			mCurrentAnimation = &mJumpLeftAnimation;
		}
		else
		{
			mCurrentAnimation->resetFrameCount();
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if(mFlower == NULL)
		{
			mFlower = new Flower(getPosition() + sf::Vector2f(128, 240));
			EntityManager::getInstance()->addEntity(mFlower);
		}
		mFlower->grow();
	}
	else
	{
		if(mFlower != NULL)
		{
			mFlower->isNotGrowing();
		}
		mFlower = NULL;
	}
}

