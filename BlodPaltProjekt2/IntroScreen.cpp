#include "IntroScreen.h"
#include "Super.h"
#include "MainMenu.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>


//Constructor, running the initialization function
IntroScreen::IntroScreen()
{
	init();
}


IntroScreen::~IntroScreen()
{
}

////Update function that handles keyboard integration with menu
void IntroScreen::update(Super &r_super)
{
	if(mMenuClock.getElapsedTime().asSeconds() > 10)
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
	r_super.getWindow().draw(mMenuSprite);
}

//Assigning a texture to a sprite
//Restarts the stopwatch
void IntroScreen::init()
{
	mMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage(""));
	mMenuSprite.setTexture(mMenuTexture);

	mMenuClock.restart();
}
