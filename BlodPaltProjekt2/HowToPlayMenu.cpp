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
	mMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("")); 
	mBackTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage(""));


	mMenuSprite.setTexture(mMenuTexture);
	mBackSprite.setTexture(mBackTexture);
}