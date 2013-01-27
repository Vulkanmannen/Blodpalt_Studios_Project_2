#include "Flower.h"
#include "Animation.h"
#include "EntityManager.h"
#include "ResourceHandler.h"
#include <cassert>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>



Flower::Flower(sf::Vector2f position, bool growLeft, GrowthDir dir) :
	mFlowerTex ( new sf::Texture() ),
	mFlowerAnimation("BLOMMA.png", 100, 32),
	mIdleAnimation("idle_sprite.png", 0, 1),
	mGrowLeft(growLeft)
{	
	mLifeTime = 300;
	mIsGrowing = true;
	mGrowthDir = dir;
		//
	auto image =  ResourceHandler::getInstance()->loadImage("BLOMMA.png");
	mFlowerTex->loadFromImage( *image );

		//Assign hitbox bounds
	if (mGrowthDir == VERTICAL ){
		mHitBox.width = 128;
		mHitBox.height = 48;
	}
	else{
		mHitBox.width = 30;
		mHitBox.height = 128;
	}
	mHitBox.top = position.y;
	mHitBox.left = position.x;
		//Assign entity kind
	mEntityKind = Entity::FLOWER;
	mLayer = BACK;
		//The new flower is active
	mIsActive = true;


	

	
	mCurrentAnimation = &mFlowerAnimation;
	mCurrentAnimation->setPosition(position);
	mCurrentAnimation->getSprite().setTextureRect(sf::IntRect(0, 0, 128, 48));

	if( mGrowthDir == HORIZONTAL)
	{
		if(mGrowLeft)
		{
			mFlowerAnimation.getSprite().rotate( 270 );
			mIdleAnimation.getSprite().rotate ( 270 );
			mFlowerAnimation.setPosition(mFlowerAnimation.getSprite().getPosition() + sf::Vector2f(0, 128));
			mIdleAnimation.setPosition(mIdleAnimation.getSprite().getPosition() + sf::Vector2f(0, 128));

		}
		else
		{
			mFlowerAnimation.getSprite().rotate( 90 );
			mIdleAnimation.getSprite().rotate ( 90 );
		}
	}
}


Flower::~Flower()
	{}


void Flower::update()
{	
	//mIdleAnimation.setPosition(getPosition());

	mCurrentAnimation->update();
	
	//mCurrentAnimation->setPosition(getPosition());

	if(mCurrentAnimation == &mFlowerAnimation && mCurrentAnimation->endOfAnimation() == true)
	{
		sf::IntRect rect = mCurrentAnimation->getSprite().getTextureRect();
		mCurrentAnimation = &mIdleAnimation;

		mCurrentAnimation->getSprite().setTextureRect(rect);
		
	}

	if( !mIsGrowing )
		--mLifeTime;

	if( mLifeTime <= 0 )
		mIsActive = !mIsActive;
}

void Flower::render(sf::RenderWindow &window)
{
	window.draw( mCurrentAnimation->getSprite() );
	//Super *super = Super::getInstance();
	//super->getWindow().draw();
}

void Flower::onCollision(Entity *e, sf::FloatRect &result)
{
	if(e->getEntityKind() == NORMALBLOCK)
	{
		if(result.height > result.width)
		{
			if(result.left > mHitBox.left)
			{
				mHitBox.left -= result.width;
				mIsGrowing = false;
			}
			else
			{
				mHitBox.left += result.width;
				mIsGrowing = false;
			}
		}
		else
		{
			if(e->getHitBox().top < mHitBox.top)
			{
				mHitBox.top += result.height;
				mIsGrowing = false;
			}
			
		}
	}
}

void Flower::grow()
{
	if( abs(mCurrentAnimation->getSprite().getTextureRect().height) >= 640 )
	{
		mIsGrowing = false;
	}

	if( mIsGrowing && mGrowthDir == VERTICAL )
	{
		auto tempRect = mCurrentAnimation->getSprite().getTextureRect();
		tempRect.height += 3;
		mCurrentAnimation->getSprite().setTextureRect( tempRect );
		mCurrentAnimation->getSprite().setPosition( mCurrentAnimation->getSprite().getPosition().x, mCurrentAnimation->getSprite().getPosition().y - 3);
		mHitBox.top = mCurrentAnimation->getSprite().getPosition().y;
	}

	else if(mIsGrowing && mGrowthDir == HORIZONTAL)
	{
		if( abs(mHitBox.width) <= 48 )
		{
			mHitBox.width -1;
		}

		if(mGrowLeft)
		{
			auto tempRect = mCurrentAnimation->getSprite().getTextureRect();
			tempRect.height += 3;
			mCurrentAnimation->getSprite().setTextureRect( tempRect );
			mCurrentAnimation->setPosition( sf::Vector2f(mCurrentAnimation->getSprite().getPosition().x - 3, mCurrentAnimation->getSprite().getPosition().y));
			mIdleAnimation.setPosition(sf::Vector2f(mCurrentAnimation->getSprite().getPosition().x - 3, mCurrentAnimation->getSprite().getPosition().y));
			mHitBox.left = mCurrentAnimation->getSprite().getPosition().x;
		}
		else
		{
			auto tempRect = mCurrentAnimation->getSprite().getTextureRect();
			tempRect.height += 3;
			mCurrentAnimation->getSprite().setTextureRect( tempRect );
			mCurrentAnimation->setPosition( sf::Vector2f(mCurrentAnimation->getSprite().getPosition().x + 3, mCurrentAnimation->getSprite().getPosition().y));
			mIdleAnimation.setPosition(sf::Vector2f(mCurrentAnimation->getSprite().getPosition().x + 3, mCurrentAnimation->getSprite().getPosition().y));
			mHitBox.left = mCurrentAnimation->getSprite().getPosition().x;
		}
	}
}

void Flower::isNotGrowing(){
	mIsGrowing = false;
}

Flower::GrowthDir Flower::getGrowthDir()
{
	return mGrowthDir;
}