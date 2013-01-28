#include "WorldMapState.h"

#include "ResourceHandler.h"
#include "Super.h"
#include "GameState.h"
#include "LoadingState.h"

#include <SFML\Window\Mouse.hpp>
class EntityManager;


WorldMapState::WorldMapState() :
	mLocked(1)
{
	mPressed = false;
	init();
}

WorldMapState::~WorldMapState() {}


void WorldMapState::draw(Super &r_super)
{
	r_super.getWindow().draw(mMapSprite);
	r_super.getWindow().draw(mLevelOneS);
	r_super.getWindow().draw(mLevelTwoS);
	r_super.getWindow().draw(mLevelThreeS);
}

void WorldMapState::update(Super &r_super)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mPressed)
	{
		if(mLevelOneRect.getTextureRect().contains(mousePos))
		{
			LoadingState loadState("Level_1.png");
			loadState.loadLevel();
			r_super.getStateManager().pushState(new GameState());
		}
		if(mLevelTwoRect.getTextureRect().contains(mousePos) && mLocked >= 2)
		{
			LoadingState loadState("Level_2.png");
			loadState.loadLevel();
			r_super.getStateManager().pushState(new GameState());
		}
		if(mLevelThreeRect.getTextureRect().contains(mousePos))
		{
			LoadingState loadState("Level_3.png");
			loadState.loadLevel();
			r_super.getStateManager().pushState(new GameState());
		}
	}
	if( !sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		mPressed = true;
}

void WorldMapState::init()
{
		//Load textures
	mMapTexture.loadFromImage(*ResourceHandler::getInstance()->loadImage("MenuImages/bgb.png"));
	mLevelOneT.loadFromImage(*ResourceHandler::getInstance()->loadImage("MenuImages/level_placeholder.png"));
	mLevelTwoT.loadFromImage(*ResourceHandler::getInstance()->loadImage("MenuImages/level_placeholder.png"));
	mLevelThreeT.loadFromImage(*ResourceHandler::getInstance()->loadImage("MenuImages/level_placeholder.png"));
	mMapSprite.setTexture(mMapTexture);
	mMapSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));

		//Assign textures and positions
	mLevelOneS.setTexture(mLevelOneT);
	mLevelOneS.setPosition(mMapSprite.getPosition() + sf::Vector2f(650, 540));
	mLevelOneRect.setTexture(mLevelOneT);
	mLevelOneRect.setTextureRect(sf::IntRect(650, 540, 150, 150));


	mLevelTwoS.setTexture(mLevelTwoT);
	mLevelTwoS.setPosition(mMapSprite.getPosition() + sf::Vector2f(800, 540));
	mLevelTwoRect.setTexture(mLevelTwoT);
	mLevelTwoRect.setTextureRect(sf::IntRect(800, 540, 150, 150));

	mLevelThreeS.setTexture(mLevelThreeT);
	mLevelThreeS.setPosition(mMapSprite.getPosition() + sf::Vector2f(950, 540));
	mLevelThreeRect.setTexture(mLevelThreeT);
	mLevelThreeRect.setTextureRect(sf::IntRect(950, 540, 150, 150));

}