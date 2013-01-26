#include "MainMenu.h"
#include "Super.h"
#include "OptionMenu.h"
#include "LevelMenu.h"
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "ResourceHandler.h"
#include "HowToPlayMenu.h"

//Constructor, running the initialization function
MainMenu::MainMenu()
{
	init();
}

MainMenu::~MainMenu()
{
}


//Update function that handles mouse integration with menu buttons
void MainMenu::update(Super &r_super)
{

}

//Draw menu sprites on display
void MainMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mOptionSprite);
	r_super.getWindow().draw(mHowToPlaySprite);
	r_super.getWindow().draw(mQuitSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void MainMenu::init()
{
	mPlayTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage(""));
	mOptionTexture.loadFromImage	( *ResourceHandler::getInstance()->loadImage(""));
	mHowToPlayTexture.loadFromImage ( *ResourceHandler::getInstance()->loadImage(""));
	mQuitTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage(""));


	mPlaySprite.setTexture(mPlayTexture);
	mOptionSprite.setTexture(mOptionTexture);
	mHowToPlaySprite.setTexture(mHowToPlayTexture);
	mQuitSprite.setTexture(mQuitTexture);
}