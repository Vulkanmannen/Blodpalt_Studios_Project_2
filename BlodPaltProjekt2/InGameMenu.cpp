#include "InGameMenu.h"
#include "Super.h"
#include "MainMenu.h"
#include "OptionMenu.h"
#include <SFML\Window\Mouse.hpp>
#include "ImageManager.h"
#include "LevelMenu.h"


//Constructor, running the initialization function
InGameMenu::InGameMenu()
{
	init();
}


InGameMenu::~InGameMenu()
{
}

void InGameMenu::buttonAnimation(Super &r_super)
{
	m_resumeSprite.setTexture(*m_currentResumeTexture);
	m_chooseSprite.setTexture(*m_currentChooseTexture);
	m_optionsSprite.setTexture(*m_currentOptionsTexture);
	m_mainMenuSprite.setTexture(*m_currentMainMenuTexture);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	
	//Resume hover
	if(m_resumeTextRect.getTextureRect().contains(mousePos))
	{
		m_currentResumeTexture = &m_resumeTextureHover;
	}
	else 
		m_currentResumeTexture = &m_resumeTexture;

	//Choose hover
	if(m_chooseTextRect.getTextureRect().contains(mousePos))
	{
		m_currentChooseTexture = &m_chooseTextureHover;
	}
	else 
		m_currentChooseTexture = &m_chooseTexture;

	//Options hover
	if(m_optionsTextRect.getTextureRect().contains(mousePos))
	{
		m_currentOptionsTexture = &m_optionsTextureHover;
	}
	else 
		m_currentOptionsTexture = &m_optionsTexture;

	//Quit hover
	if(m_mainMenuTextRect.getTextureRect().contains(mousePos))
	{
		m_currentMainMenuTexture = &m_mainMenuTextureHover;
	}
	else 
		m_currentMainMenuTexture = &m_mainMenuTexture;
}


//Update function that handles mouse integration with menu buttons
void InGameMenu::update(Super &r_super)
{
	int timer = 0;

	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{		
		//How to play button
		if(m_resumeTextRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().popState();
		}
		if(m_chooseTextRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().pushState(new LevelMenu());
		}

		//Option button
		if(m_optionsTextRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().pushState(new OptionMenu());
		}

		//Quit button
		if(m_mainMenuTextRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().popState();
			r_super.getStateManager().pushState(new MainMenu());
		}
	}
}

//Draw menu sprites on display
void InGameMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(m_menuSprite);
	r_super.getWindow().draw(m_resumeSprite);
	r_super.getWindow().draw(m_chooseSprite);
	r_super.getWindow().draw(m_optionsSprite);
	r_super.getWindow().draw(m_mainMenuSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void InGameMenu::init()
{
	m_menuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("MenuBackground.png"));
	m_resumeTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_resume_button.png"));
	m_chooseTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_button.png"));
	m_optionsTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_button.png"));
	m_mainMenuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_mainMenu_button.png"));

	m_resumeTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_resume_hover.png"));
	m_chooseTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_hover.png"));
	m_optionsTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_hover.png"));
	m_mainMenuTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_mainMenu_hover.png"));

	m_resumeTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_how_click.png"));
	m_chooseTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_click.png"));
	m_optionsTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_click.png"));
	m_mainMenuTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_quit_click.png"));

	m_currentResumeTexture = &m_resumeTexture;
	m_currentChooseTexture = &m_chooseTexture;
	m_currentOptionsTexture = &m_optionsTexture;
	m_currentMainMenuTexture = &m_mainMenuTexture;


	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(640, 360));


	m_resumeSprite.setTexture(m_resumeTexture);
	m_resumeSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 327));
	m_resumeTextRect.setTexture(m_resumeTexture);
	m_resumeTextRect.setTextureRect(sf::IntRect(516, 327, 250, 65));


	m_chooseSprite.setTexture(m_chooseTexture);
	m_chooseSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 402));
	m_chooseTextRect.setTexture(m_chooseTexture);
	m_chooseTextRect.setTextureRect(sf::IntRect(516, 402, 250, 65));
	

	m_optionsSprite.setTexture(m_optionsTexture);
	m_optionsSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 477));
	m_optionsTextRect.setTexture(m_optionsTexture);
	m_optionsTextRect.setTextureRect(sf::IntRect(516, 477, 250, 65));

	
	m_mainMenuSprite.setTexture(m_mainMenuTexture);
	m_mainMenuSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 552));
	m_mainMenuTextRect.setTexture(m_mainMenuTexture);
	m_mainMenuTextRect.setTextureRect(sf::IntRect(516, 552, 250, 65));
}