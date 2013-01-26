#include "LoadingState.h"
//#include "Super.h"
#include "EntityManager.h"
#include "ResourceHandler.h"
#include "NormalBlock.h"
#include "MovingBlock.h"
#include "Arvid.h"

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
			sf::Vector2f position = sf::Vector2f(i * 32, j * 32);

			if(color == sf::Color(0, 0, 0, 255))
			{
				mEntityManager->addEntity(new NormalBlock(position));
			}
		
			else if(color == sf::Color(255, 0, 0, 255))
			{
				mEntityManager->addEntity(new MovingBlock(position));
			}

			else if(color == sf::Color(0, 0, 255, 255))
			{
				mEntityManager->addEntity(new MovingBlock(position, MovementMode::VERTICAL));
			}

			else if(color == sf::Color(255, 255, 0, 255))
			{
				mEntityManager->addEntity(new Arvid(position));
			}
		}
	}
}