#include "GameState.h"
#include "EntityManager.h"
#include "Super.h"
#include "InGameMenu.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>


GameState::GameState()
{
	init();
}

GameState::~GameState()
{
}

void GameState::update(Super &r_super)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		r_super.getStateManager().pushState(new InGameMenu());
	}



	//EntityManager::getInstance()->update();
}

void GameState::draw(Super &r_super) 
{



	//EntityManager::getInstance()->render();
}

void GameState::init()
{

}

////skapar bakgrunden
//void GameState::createBackground()
//{
//	for(int i = 0; i < 9; i++)
//	{
//		m_backgroundVector.push_back(new sf::Sprite(m_backgroundTexture));
//		m_backgroundVector[i]->setOrigin(m_backgroundVector[i]->getLocalBounds().width / 2, m_backgroundVector[i]->getLocalBounds().height / 2);
//	}
//	m_backgroundVector[4]->setPosition(Man::getInstance()->position());
//}
//
////Uppdaterar bakgrunden 
//void GameState::updateBackground()
//{
//	moveBackground();
//	sf::Vector2f pos = m_backgroundVector[4]->getPosition() - sf::Vector2f(512, 512);
//	for(int j = 0; j < 3; j++)
//	{
//		for(int k = 0; k < 3; k++)
//		{
//			m_backgroundVector[j * 3 + k]->setPosition(pos.x + j * 512, pos.y + k * 512);
//		}
//	}
//	checkClosestSquare();
//}
//
////Ritar ut bakgrunden
//void GameState::drawBackground(Super &r_super)
//{
//	for(int i = 0; i < 9; i++)
//	{
//		r_super.getWindow().draw(*m_backgroundVector[i]);
//	}
//}
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