#include "Arvid.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>

static const float	MAXRUNSPEED		= 2;
static const float	MAXJUMPSPEED	= 5;
static const int	JUMPTIME		= 10;

Arvid::Arvid(sf::Vector2f &position):/*
	mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("", 0, 0),
	mRunLeftAnimation	("", 0, 0),
	mRunRightAnimation	("", 0, 0),
	mJumpAnimation		("", 0, 0)*/
	mMovementSpeed(0,1),
	mRunSpeed(1),
	mJumping(false),
	mJumpDecrease(1),
	mJumpTime(0)
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
}

void Arvid::render(sf::RenderWindow &window)
{
	mSprite.setPosition(getPosition());
	window.draw(mSprite);
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mJumping == false)
	{
		mJumping == true;
		mMovementSpeed.y = -MAXJUMPSPEED;
	}
}

void Arvid::jumping()
{
	if(mJumping)
	{
		mMovementSpeed.y += mJumpDecrease;
		++mJumpTime;
		
		if(mJumpTime >= JUMPTIME)
		{
			mJumpTime = 0;
			mJumping = false;
		}
	}
}

void Arvid::onCollision()
{

}