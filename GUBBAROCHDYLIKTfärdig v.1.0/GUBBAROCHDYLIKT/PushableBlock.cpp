#include "PushableBlock.h"


PushableBlock::PushableBlock(sf::Vector2f &position):
	mNormalCount(0)
{
	setPosition(position);
	mEntityKind = EntityKind::PUSHABLEBLOCK;
	mLayer		= MIDDLE;
	mTexture.loadFromFile("BLOCK.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(position);
	mHitBox = sf::FloatRect(position, sf::Vector2f(64, 64));
}


PushableBlock::~PushableBlock()
{
}

void PushableBlock::update()
{
	if(mEntityKind == NORMALBLOCK)
	{
		++mNormalCount;
		if(mNormalCount >= 10)
		{
			mEntityKind = PUSHABLEBLOCK;
			mNormalCount = 0;
		}
	}
	mSprite.setPosition(sf::Vector2f(mHitBox.left, mHitBox.top));
}

void PushableBlock::render(sf::RenderWindow &window)
{
	window.draw(mSprite);
}

void PushableBlock::onCollision(Entity *e, sf::FloatRect &result)
{
	EntityKind kind = e->getEntityKind();

	if(kind == FLOWER || kind == PUSHABLEBLOCK)
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
				mHitBox.top -= result.height;
			}
		}
	}
	
	else if(kind == NORMALBLOCK)
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
			mHitBox.top += result.height;
		}
		mEntityKind = NORMALBLOCK;
	}
}