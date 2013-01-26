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

Arvid::Arvid(sf::Vector2f &position):/*
	mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("", 0, 0),
	mRunLeftAnimation	("", 0, 0),
	mRunRightAnimation	("", 0, 0),
	mJumpAnimation		("", 0, 0)*/
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
	mHitBox = sf::FloatRect(position, sf::Vector2f(128, 128));
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
}

void Arvid::render(sf::RenderWindow &window)
{
	mSprite.setPosition(getPosition());
	window.draw(mSprite);
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
		//if(mFlower == NULL)
		//{
		//	mFlower = new Flower();
		//	EntityManager::getInstance()->addEntity(mFlower);
		//}
		//mFlower->grow();
	}
	else
	{
		mFlower = NULL;
	}
}

