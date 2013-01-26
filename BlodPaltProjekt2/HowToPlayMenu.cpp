#include "HowToPlayMenu.h"
#include "ResourceHandler.h"
#include "Super.h"

HowToPlayMenu::HowToPlayMenu()
{
	init();
}

HowToPlayMenu::~HowToPlayMenu()
{
}



void HowToPlayMenu::update(Super &r_super)
{
	
}

void HowToPlayMenu::draw(Super &r_super) 
{

}

void HowToPlayMenu::init()
{
	mMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/BACKGROUND_MENU.png")); 
	mBackTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/back_button.png"));


	mMenuSprite.setTexture(mMenuTexture);
	mBackSprite.setTexture(mBackTexture);
}