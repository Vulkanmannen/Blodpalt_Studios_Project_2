#include "HowToPlayMenu.h"
#include "ImageManager.h"
#include "Super.h"

HowToPlayMenu::HowToPlayMenu()
{
	init();
}

HowToPlayMenu::~HowToPlayMenu()
{
}

void HowToPlayMenu::buttonAnimation(Super &r_super)
{
	m_backSprite.setTexture(*m_currentBackTexture);


	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	
	//Resume hover
	if(m_backTextureRect.getTextureRect().contains(mousePos))
	{
		m_currentBackTexture = &m_backTextureHover;
	}
	else 
		m_currentBackTexture = &m_backTexture;
}

void HowToPlayMenu::update(Super &r_super)
{
	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{		
		//Back button
		if(m_backTextureRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().popState();
		}
	}
}

void HowToPlayMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(m_menuSprite);
	r_super.getWindow().draw(m_backSprite);
}

void HowToPlayMenu::init()
{
	m_menuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("HowToMenu.png"));
	m_backTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_back_button.png"));
	m_backTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_back_hover.png"));

	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(640, 360));

	m_backSprite.setTexture(m_backTexture);
	m_backSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 617));
	m_backTextureRect.setTextureRect(sf::IntRect(516, 617, 250, 65));
	m_backTextureRect.setPosition(516, 617);

	m_currentBackTexture = &m_backTexture;
}