#include "InGameMenu.h"
#include "Super.h"
#include "MainMenu.h"
#include "ResourceHandler.h"

#include <SFML\Window\Keyboard.hpp>

//Constructor, running the initialization function
InGameMenu::InGameMenu()
{
	init();
}


InGameMenu::~InGameMenu()
{
}


void InGameMenu::update(Super &r_super)
{
	if(/*RESUMEKNAPPEN BLIVIT VALD*/)
	{
		r_super.getStateManager().popState();
	}

	if(/*MAIN MENU BLIVIT VALD*/)
	{
		r_super.getStateManager().popState();
	}
}

//Draw menu sprites on display
void InGameMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mReturnToMainMenuSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void InGameMenu::init()
{
	mMenuTexture.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage(""));
	mReturnToMainMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage(""));


	mMenuSprite.setTexture(mMenuTexture);
	mReturnToMainMenuSprite.setTexture(mReturnToMainMenuTexture);
}