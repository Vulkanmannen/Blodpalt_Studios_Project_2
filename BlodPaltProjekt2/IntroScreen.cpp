#include "IntroScreen.h"
#include "Super.h"
#include "MainMenu.h"
#include "ImageManager.h"
#include <SFML\Window\Keyboard.hpp>


//Constructor, running the initialization function
IntroScreen::IntroScreen()
{
	m_menuTexture.loadFromImage(*ImageManager::getInstance()->loadImage("MenuBackground.png"));
	init();
}


IntroScreen::~IntroScreen()
{
}

////Update function that handles keyboard integration with menu
void IntroScreen::update(Super &r_super)
{
	if(m_menuClock.getElapsedTime().asSeconds() > 3)
	{
		r_super.getStateManager().popState();
		r_super.getStateManager().pushState(new MainMenu());
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		r_super.getStateManager().popState();
		r_super.getStateManager().pushState(new MainMenu());
	}
}

//Draw menu sprites on display
void IntroScreen::draw(Super &r_super) 
{
	r_super.getWindow().draw(m_menuSprite);
	r_super.getWindow().setView(r_super.getView());
}

//Assigning a texture to a sprite
//Restarts the stopwatch
void IntroScreen::init()
{
	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(640, 360));
	m_menuClock.restart();
}
