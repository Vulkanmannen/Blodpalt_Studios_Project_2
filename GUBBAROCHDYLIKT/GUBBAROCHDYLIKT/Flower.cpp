#include "Flower.h"
#include "Animation.h"
#include "EntityManager.h"
#include "ResourceHandler.h"
#include <cassert>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>



Flower::Flower(sf::Vector2f position, GrowthDir dir) :
	mFlowerTex ( new sf::Texture() )
{	
	mLifeTime = 600;
	mIsGrowing = true;
	mGrowthDir = dir;
		//
	auto image =  ResourceHandler::getInstance()->loadImage("BLOMMA.png");
	mFlowerTex->loadFromImage( *image );

		//Assign hitbox bounds
	if (mGrowthDir == VERTICAL ){
		mHitBox.width = 128;
		mHitBox.height = 0;
	}
	else{
		mHitBox.width = 0;
		mHitBox.height = 48;
	}
	mHitBox.top = position.y;
	mHitBox.left = position.x;
		//Assign entity kind
	mEntityKind = Entity::FLOWER;
		//The new flower is active
	mIsActive = true;
		//Set it's sprite's stats
	mSprite.setTexture( *mFlowerTex );
	mSprite.setPosition( position );
	mSprite.setTextureRect( sf::IntRect(0,0,128,0) );
	if( mGrowthDir == HORIZONTAL)
		mSprite.rotate( 90 );
}


Flower::~Flower()
	{}


void Flower::update()
{	

	//static Entity* flower2 = new Flower(sf::Vector2f(600,800), HORIZONTAL);
	//static Entity* flower = new Flower(sf::Vector2f( 800,600 ), VERTICAL );
	//static bool once = true;


	//if(once){
	//	EntityManager::getInstance()->addEntity( flower );
	//	EntityManager::getInstance()->addEntity( flower2 );
	//	once = !once;

	//}
	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) ){
	//	dynamic_cast<Flower*>(flower)->grow();
	//	dynamic_cast<Flower*>(flower2)->grow();
	//}

	if( !mIsGrowing )
		--mLifeTime;

	if( mLifeTime <= 0 )
		mIsActive = !mIsActive;
}

void Flower::render(sf::RenderWindow &window)
{
		window.draw( mSprite );
	//Super *super = Super::getInstance();
	//super->getWindow().draw();
}

void Flower::onCollision(Entity *e){

};

void Flower::grow(){
	if( abs(mSprite.getTextureRect().height) >= 640 )
		mIsGrowing = false;

	if( mIsGrowing )
	{
		if(mGrowthDir == VERTICAL){
			if( abs(mHitBox.height) < 48 )
				mHitBox.height -= 1;

			auto tempRect = mSprite.getTextureRect();
			tempRect.top += 1;
			tempRect.height -= 1;
			mSprite.setTextureRect( tempRect );
			mHitBox.top = tempRect.top;

		}
		else if(mGrowthDir == HORIZONTAL){
			if( abs(mHitBox.width) <= 48 )
				mHitBox.width -1;
			
			auto tempRect = mSprite.getTextureRect();
			tempRect.top += 1;
			tempRect.height -= 1;
			mSprite.setTextureRect( tempRect );
			mHitBox.left = tempRect.left - mHitBox.width; 
		}
	}
}

void Flower::isNotGrowing(){
	mIsGrowing = false;
}