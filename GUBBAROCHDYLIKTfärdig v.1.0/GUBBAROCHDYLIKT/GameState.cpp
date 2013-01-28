#include "GameState.h"
#include "Super.h"
#include "InGameMenu.h"
#include "Super.h"
#include "InGameMenu.h"
#include "ResourceHandler.h"
#include "Entity.h"
#include <SFML\Window\Keyboard.hpp>


GameState::GameState()
{
	e = EntityManager::getInstance();
	Super::getInstance()->playMusic("level");
	init();
	
}

GameState::~GameState()
{
	e->clearAll();
}

void GameState::update(Super &r_super)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		r_super.getStateManager().pushState(new InGameMenu());
	}
	updateBackground();
	e->update();
}

void GameState::draw(Super &r_super) 
{
	r_super.getView().setCenter(sf::Vector2f(e->getArvid()->getPosition()));
	drawBackground(r_super);
	e->render(r_super.getWindow());
}

void GameState::init()
{
	createBackground();
	sf::Vector2f mLastPosition = EntityManager::getInstance()->getArvid()->getPosition();
}

//skapar bakgrunden
void GameState::createBackground()
{
	mBackgroundTexture.loadFromFile("bgb1.png");
	
	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			sf::Sprite* sprite = new sf::Sprite();
			sprite->setTexture(mBackgroundTexture);
			sprite->setPosition(-1000 + 1000 * i, -1000 + 1000 *j);

			m_backgroundVector.push_back(sprite);
		}
	}
}

void GameState::updateBackground()
{
	sf::Vector2f position = EntityManager::getInstance()->getArvid()->getPosition();
	if(mLastPosition != position)
	{
		sf::Vector2f move = position - mLastPosition;
		for(std::vector<sf::Sprite*>::size_type i = 0; i < m_backgroundVector.size(); ++i)
		{
			m_backgroundVector[i]->setPosition(m_backgroundVector[i]->getPosition() + sf::Vector2f(move.x * 0.5, move.y *0.5));
		}
		mLastPosition = EntityManager::getInstance()->getArvid()->getPosition();
	}
}

//Ritar ut bakgrunden
void GameState::drawBackground(Super &r_super)
{
	for(std::vector<sf::Sprite*>::size_type i = 0; i < m_backgroundVector.size(); ++i)
	{
		r_super.getWindow().draw(*m_backgroundVector[i]);
	}
}
//
////Kollar vilken av texturerna som är närmast, tilldelar denna mitten 
//void GameState::checkClosestSquare()
//{
//	int newMid = 0;
//	sf::Vector2f difference = Man::getInstance()->position() - m_backgroundVector[4]->getPosition();
//	//Kollar om bakgrundens xPos resp. yPos är större eller mindre än texturen strlk
//	if(difference.x > 256)
//	{
//		newMid = getSquare(m_backgroundVector[4]->getPosition() + sf::Vector2f(512, 0)); 
//		changeMidSquare(newMid);
//	}
//
//	else if(difference.x < -256)
//	{
//		newMid = getSquare(m_backgroundVector[4]->getPosition() + sf::Vector2f(-512, 0)); 
//		changeMidSquare(newMid);
//	}
//
//	else if(difference.y > 256)
//	{
//		newMid = getSquare(m_backgroundVector[4]->getPosition() + sf::Vector2f(0, 512)); 
//		changeMidSquare(newMid);
//	}
//
//	else if(difference.y < -256)
//	{
//		newMid = getSquare(m_backgroundVector[4]->getPosition() + sf::Vector2f(0, -512)); 
//		changeMidSquare(newMid);
//	}
//}
//
////Hämtar in en ny texturruta
//int GameState::getSquare(sf::Vector2f square)
//{
//	for(int i = 0; i < 9; i++)
//	{
//		if(m_backgroundVector[i]->getPosition() == square)
//		{
//			return i;
//		}
//	}
//}
//
//void GameState::changeMidSquare(int newMid)
//{
//	sf::Sprite* temp;
//	temp = m_backgroundVector[4];
//	m_backgroundVector[4] = m_backgroundVector[newMid];
//	m_backgroundVector[newMid] = temp;
//}
//
//void GameState::moveBackground()
//{
//	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//	{
//		m_backgroundVector[4]->setPosition(m_backgroundVector[4]->getPosition() - sf::Vector2f(2.5, 0));
//	}
//	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//	{
//		m_backgroundVector[4]->setPosition(m_backgroundVector[4]->getPosition() + sf::Vector2f(2.5, 0));
//	}
//}