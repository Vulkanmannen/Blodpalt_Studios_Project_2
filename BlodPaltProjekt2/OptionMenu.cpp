#include "OptionMenu.h"
#include "Super.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceHandler.h"


OptionMenu::OptionMenu()
{
	init();
}


OptionMenu::~OptionMenu()
{
}


//Update function that handles mouse integration with menu buttons
void OptionMenu::update(Super &r_super)
{

}

//Draw menu sprites on display
void OptionMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mBackSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void OptionMenu::init()
{
	mMenuTexture.loadFromImage	( *ResourceHandler::getInstance()->loadImage(""));
	mBackTexture.loadFromImage	( *ResourceHandler::getInstance()->loadImage(""));
	
	mMenuSprite.setTexture(mMenuTexture);
	mBackSprite.setTexture(mBackTexture);
	
}