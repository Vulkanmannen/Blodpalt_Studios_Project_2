#include "LevelMenu.h"
#include "Super.h"
#include "GameState.h"
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "ImageManager.h"
#include "LevelManager.h"


LevelMenu::LevelMenu()
{
	init();
}

LevelMenu::~LevelMenu()
{
}

void LevelMenu::update(Super &r_super)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		r_super.getStateManager().popState();
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if(m_level1.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().clear();
			LevelManager::getInstance()->loadLevel(1);
			r_super.getStateManager().pushState(new GameState());
		}
		if(m_level2.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().clear();
			LevelManager::getInstance()->loadLevel(2);
			r_super.getStateManager().pushState(new GameState());
		}
	}
}

void LevelMenu::drawGoldPieces(int level)
{
	Super* super = Super::getInstance();
	sf::Vector2f temp = m_levelVector[level - 1].getPosition(); 
	temp = temp + sf::Vector2f(0, 370);
	m_goldCoinSprite.setPosition(temp);
	for(int i = 0; i < LevelManager::getInstance()->getGatheredPieces(level); ++i)
	{
		super->getWindow().draw(m_goldCoinSprite);
		temp.x += 20;
		m_goldCoinSprite.setPosition(temp);
	}
}

void LevelMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(m_menuSprite);
	r_super.getWindow().draw(m_level1);
	r_super.getWindow().draw(m_level2);
	drawGoldPieces(1);
	drawGoldPieces(2);
	/*
	drawGoldPieces(3);
	drawGoldPieces(4);
	drawGoldPieces(5);
	drawGoldPieces(6);
	*/
}

void LevelMenu::init()
{
	m_menuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("MenuBackground.png"));
	m_goldCoinTexture.loadFromImage(*ImageManager::getInstance()->loadImage("GoldCoin.png"));

	LevelManager::getInstance()->gatheredPieces();

	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(640, 360));
	
	m_level1.setTexture(m_menuTexture);
	m_level1.setTextureRect(sf::IntRect(115, 82, 363, 421));
	m_level1.setPosition(m_menuSprite.getPosition() + sf::Vector2f(115, 82));

	m_level2.setTexture(m_menuTexture);
	m_level2.setTextureRect(sf::IntRect(612, 81, 363,421));
	m_level2.setPosition(m_menuSprite.getPosition() + sf::Vector2f(612, 81));
	m_levelVector.push_back(m_level1);
	m_levelVector.push_back(m_level2);
	m_goldCoinSprite.setTexture(m_goldCoinTexture);
}
