#include "MainMenu.h"
#include "Super.h"
#include "OptionMenu.h"
#include "LevelMenu.h"
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "ImageManager.h"
#include "HowToPlayMenu.h"

//Constructor, running the initialization function
MainMenu::MainMenu()
{
	init();
}

MainMenu::~MainMenu()
{
}

void MainMenu::buttonAnimation(Super &r_super)
{
	m_chooseSprite.setTexture(*m_currentChooseTexture);
	m_howToPlaySprite.setTexture(*m_currentHowToTexture);
	m_optionsSprite.setTexture(*m_currentOptionsTexture);
	m_quitSprite.setTexture(*m_currentQuitTexture);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	
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

	//How To hover
	if(m_howToPlayTextRect.getTextureRect().contains(mousePos))
	{
		m_currentHowToTexture = &m_howToPlayTextureHover;
	}
	else 
		m_currentHowToTexture = &m_howToPlayTexture;

	//Quit hover
	if(m_QTextRect.getTextureRect().contains(mousePos))
	{
		m_currentQuitTexture = &m_quitTextureHover;
	}
	else 
		m_currentQuitTexture = &m_quitTexture;
}

//Update function that handles mouse integration with menu buttons
void MainMenu::update(Super &r_super)
{
	int timer = 0;

	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if(m_chooseTextRect.getTextureRect().contains(mousePos))
		{
			//m_currentChooseTexture = &m_chooseTextureClick;
			r_super.getStateManager().pushState(new LevelMenu());
		}

		//Option button
		if(m_optionsTextRect.getTextureRect().contains(mousePos))
		{
			//m_currentOptionsTexture = &m_optionsTextureClick;
			r_super.getStateManager().pushState(new OptionMenu());
		}

		//How to play button
		if(m_howToPlayTextRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().pushState(new HowToPlayMenu());
		}

		//Quit button
		if(m_QTextRect.getTextureRect().contains(mousePos))
		{
			//m_currentQuitTexture = &m_quitTextureClick;
			r_super.getWindow().close();
		}
	}
}

//Draw menu sprites on display
void MainMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(m_menuSprite);
	r_super.getWindow().draw(m_chooseSprite);
	r_super.getWindow().draw(m_optionsSprite);
	r_super.getWindow().draw(m_howToPlaySprite);
	r_super.getWindow().draw(m_quitSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void MainMenu::init()
{
	m_menuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("MenuBackground.png"));
	m_chooseTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_button.png"));
	m_optionsTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_button.png"));
	m_howToPlayTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_how_button.png"));
	m_quitTexture.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_quit_button.png"));

	m_chooseTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_hover.png"));
	m_optionsTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_hover.png"));
	m_howToPlayTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_how_hover.png"));
	m_quitTextureHover.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_quit_hover.png"));

	m_chooseTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_choose_click.png"));
	m_optionsTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_options_click.png"));
	m_howToPlayTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_how_click.png"));
	m_quitTextureClick.loadFromImage(*ImageManager::getInstance()->loadImage("main_MENU_quit_click.png"));

	m_currentChooseTexture = &m_chooseTexture;
	m_currentOptionsTexture = &m_optionsTexture;
	m_currentHowToTexture = &m_howToPlayTexture;
	m_currentQuitTexture = &m_quitTexture;


	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(640, 360));


	m_chooseSprite.setTexture(m_chooseTexture);
	m_chooseSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 327));
	m_chooseTextRect.setTexture(m_chooseTexture);
	m_chooseTextRect.setTextureRect(sf::IntRect(516, 327, 250, 65));
	

	m_optionsSprite.setTexture(m_optionsTexture);
	m_optionsSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 402));
	m_optionsTextRect.setTexture(m_optionsTexture);
	m_optionsTextRect.setTextureRect(sf::IntRect(516, 402, 250, 65));

	
	m_howToPlaySprite.setTexture(m_howToPlayTexture);
	m_howToPlaySprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 477));
	m_howToPlayTextRect.setTexture(m_howToPlayTexture);
	m_howToPlayTextRect.setTextureRect(sf::IntRect(516, 477, 250, 65));

	
	m_quitSprite.setTexture(m_quitTexture);
	m_quitSprite.setPosition(m_menuSprite.getPosition() + sf::Vector2f(516, 552));
	m_QTextRect.setTexture(m_quitTexture);
	m_QTextRect.setTextureRect(sf::IntRect(516, 552, 250, 65));
}