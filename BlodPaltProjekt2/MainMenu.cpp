#include "MainMenu.h"
#include "Super.h"

#include "HowToPlayMenu.h"
#include "ResourceHandler.h"

#include <SFML\Window\Keyboard.hpp>

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
	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//{
	//
	//}

	//else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
	//
	//}


	//if(/*SPELA KNAPPEN BLIVIT VALD*/)
	//{
	//	r_super.getStateManager().popState();
	//	r_super.getStateManager().pushState(new GameState());
	//}

	//if(/*HOWTOPLAY KNAPPEN BLIVIT VALD*/)
	//{
	//	r_super.getStateManager().popState();
	//	r_super.getStateManager().pushState(new HowToPlayMenu());		
	//}

	//if(/*QUIT KNAPPEN BLIVIT VALD*/)
	//{
	//	r_super.getStateManager().clear();		
	//}
}

//Draw menu sprites on display
void MainMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mPlaySprite);
	r_super.getWindow().draw(mHowToPlaySprite);
	r_super.getWindow().draw(mQuitSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void MainMenu::init()
{
	mMenuTexture.loadFromImage      ( *ResourceHandler::getInstance()->loadImage("MenuImages/BACKGROUND_MENU.png"));
	mPlayTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0001_Group-1-copy-2.png"));
	mHowToPlayTexture.loadFromImage ( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0002_Group-1-copy.png"));
	mQuitTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0003_Group-1.png"));

	mPlaySprite.setTextureRect		(sf::IntRect(760, 330, 400, 120));
	mPlaySprite.setPosition			(760, 327);
	mHowToPlaySprite.setTextureRect	( sf::IntRect(760, 480, 400, 120));
	mHowToPlaySprite.setPosition	(760, 480);
	mQuitSprite.setTextureRect		(sf::IntRect(760, 630, 400, 120));
	mQuitSprite.setPosition			(760, 630);

	mMenuSprite.setTexture(mMenuTexture);
	mPlaySprite.setTexture(mPlayTexture);
	mHowToPlaySprite.setTexture(mHowToPlayTexture);
	mQuitSprite.setTexture(mQuitTexture);
}