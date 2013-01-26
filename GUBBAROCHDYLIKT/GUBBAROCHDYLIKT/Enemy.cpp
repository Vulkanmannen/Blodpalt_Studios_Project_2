#include "Enemy.h"
#include "ResourceHandler.h"

Enemy::Enemy(sf::Vector2f &position, EnemyType type) :
	mMovementSpeed(3),
	mEnemyType(type) 
{
	if(mEnemyType == ALEX)
	{
		mRightAnimation = Animation("alex_walk_right.png", 0, 1);
		mLeftAnimation	= Animation("alex_walk_left.png", 0, 1);
	}
	else if(mEnemyType == JON)
	{
		mRightAnimation = Animation("", 0, 1);
		mLeftAnimation = Animation("", 0, 1);
	}
	mCurrentAnimation = &mRightAnimation;
}


Enemy::~Enemy() { }

void Enemy::update()
{
	move();

	mCurrentAnimation->update();

	mRightAnimation.setPosition(getPosition());
	mLeftAnimation.setPosition(getPosition());

	if(mWalkLeft)
	{
		mEdgeCheck = sf::Vector2f(mHitBox.left - 10, mHitBox.top + 190);
	}

	else
	{
		mEdgeCheck = sf::Vector2f(mHitBox.left + 190, mHitBox.top + 190);
	}
}

void Enemy::render(sf::RenderWindow &window)
{
	window.draw(mCurrentAnimation->getSprite());
}

void Enemy::onCollision(Entity *e, sf::FloatRect &result)
{
	EntityKind kind = e->getEntityKind();

	if(kind == NORMALBLOCK)
	{
		changeDirection();
	}
}

void Enemy::move()
{
	setPosition(sf::Vector2f(getPosition().x + mMovementSpeed, getPosition().y));

	if(mMovementSpeed > 0)
	{
		mCurrentAnimation = &mRightAnimation;
		mWalkLeft = false;
	}
	else if(mMovementSpeed < 0)
	{
		mCurrentAnimation = &mLeftAnimation;
		mWalkLeft = true;
	}
}

void Enemy::changeDirection()
{
	mMovementSpeed *= -1;
}

sf::Vector2f Enemy::getPoint()
{
	return mEdgeCheck;
}