#include "LoadingState.h"
//#include "Super.h"
#include "EntityManager.h"
#include "ResourceHandler.h"
#include "NormalBlock.h"
#include "MovingBlock.h"
#include "Arvid.h"
#include "Enemy.h"
#include "PushableBlock.h"
#include "Goal.h"

LoadingState::LoadingState(std::string filePath) :
	mLevelImage( ResourceHandler::getInstance()->loadImage(filePath) )
	{
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
	for(int i = 0; i < mLevelImage->getSize().x; ++i)
	{
		for(int j = 0; j < mLevelImage->getSize().y; ++j)
		{
			sf::Color color = mLevelImage->getPixel(i, j);
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
		}
	}
}