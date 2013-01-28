#include "LoadingState.h"
//#include "Super.h"
#include "MainMenu.h"
#include "EntityManager.h"
#include "ResourceHandler.h"
#include "NormalBlock.h"
#include "MovingBlock.h"
#include "Arvid.h"
#include "Enemy.h"
#include "PushableBlock.h"
#include "Goal.h"
#include "Super.h"
#include <sstream>
#include <cassert>
#include <fstream>
#include <string>
#include "Credits.h"

LoadingState::LoadingState(unsigned int level) 
	{
		switch(level){
		case 1:
			mLevelImage.loadFromFile("Level_1.png");
			break;
		case 2:
			mLevelImage.loadFromFile("Level_2.png");
			break;
		case 3:
			mLevelImage.loadFromFile("Level_3.png");
			break;
		case 4:
			mLevelImage.loadFromFile("Level_4.png");
			break;
		case 5:
			mLevelImage.loadFromFile("Level_5.png");
			break;
		case 6:
			mLevelImage.loadFromFile("Level_6.png");
			break;
		case 7:
			mLevelImage.loadFromFile("Level_7.png");
			break;
		case 8:
			mLevelImage.loadFromFile("Level_8.png");
			break;
		case 9:
			mLevelImage.loadFromFile("Level_9.png");
			break;
		default:
			Super::getInstance()->getStateManager().pushState(new Credits() );			
		}
		mEntityManager = EntityManager::getInstance();
	}

LoadingState::~LoadingState()
{
}

//void LoadingState::update(Super &r_super)
//{
//	loadLevel();
//	
//	//r_super.getStateManager().popState();
//}
//
//void LoadingState::draw(Super &r_super)
//{
//
//}

void LoadingState::loadLevel()
{
		//Clear entitys
	mEntityManager->clearAll();
		//Load level from image
	for(int i = 0; i < mLevelImage.getSize().x; ++i)
	{
		for(int j = 0; j < mLevelImage.getSize().y; ++j)
		{
			sf::Color color = mLevelImage.getPixel(i, j);
			sf::Vector2f position = sf::Vector2f(i * 64, j * 64);

			if(color == sf::Color(0, 0, 0, 255))
			{
				mEntityManager->addEntity(new NormalBlock(position));
			}
		
			else if(color == sf::Color(255, 0, 0, 255))
			{
				mEntityManager->addDynamicEntity(new MovingBlock(position));
			}

			else if(color == sf::Color(0, 0, 255, 255))
			{
				mEntityManager->addDynamicEntity(new Goal(position));
			}

			else if(color == sf::Color(255, 255, 0, 255))
			{
				mEntityManager->addDynamicEntity(new Arvid(position));
			}

			else if(color == sf::Color(0, 255, 255, 255))
			{
				mEntityManager->addDynamicEntity(new Enemy(position, EnemyType::ALEX));
			}

			else if(color == sf::Color(255, 0, 255, 255))
			{
				mEntityManager->addDynamicEntity(new PushableBlock(position));
			}
			else if(color == sf::Color(100, 100, 100, 255))
			{
				mEntityManager->addEntity(new Goal(position) );
			}
			else if(color == sf::Color( 50, 50, 50, 255) )
			{
				mEntityManager->addEntity(new NormalBlock(position, NormalBlock::DIRT) );
			}
		}
	}
}
