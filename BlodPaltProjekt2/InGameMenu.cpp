#include "InGameMenu.h"
#include "Super.h"
#include "MainMenu.h"
#include "OptionMenu.h"
#include <SFML\Window\Mouse.hpp>
#include "ResourceHandler.h"
#include "LevelMenu.h"


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
	
}

//Draw menu sprites on display
void InGameMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mOptionSprite);
	r_super.getWindow().draw(mReturnToMainMenuSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void InGameMenu::init()
{
	mMenuTexture.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage(""));
	mOptionTexture.loadFromImage		  ( *ResourceHandler::getInstance()->loadImage(""));
	mReturnToMainMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage(""));


	mMenuSprite.setTexture(mMenuTexture);
	mOptionSprite.setTexture(mOptionTexture);
	mReturnToMainMenuSprite.setTexture(mReturnToMainMenuTexture);
}