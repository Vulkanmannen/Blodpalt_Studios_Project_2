#include "Credits.h"
#include "Super.h"
#include "MainMenu.h"
#include "ResourceHandler.h"
#include "LoadingState.h"

#include <SFML\Window\Mouse.hpp>

//Constructor, running the initialization function
Credits::Credits()	
{
	mPressed = false;
	init();
	Super::getInstance()->playMusic("death");
}


Credits::~Credits()
{
}

void Credits::buttonAnimation(Super &r_super)
{
	mReturnToMainMenuSprite.setTexture(*mCurrentReturn);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(mReturnToMainMenuTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentReturn = &mReturnHover;
	}
	else
		mCurrentReturn = &mReturnToMainMenuTexture;
}

void Credits::update(Super &r_super)
{
	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mPressed )
	{
		
		if(mReturnToMainMenuTexRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().clear();
			r_super.getStateManager().pushState(new MainMenu());
		}
		mPressed = false;
	}
	if( !sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		mPressed = true;
}

//Draw menu sprites on display
void Credits::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mReturnToMainMenuSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void Credits::init()
{
	mMenuTexture.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage("MenuImages/Credits_menu.png"));
	mReturnToMainMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0002_main-menu.png"));
																						
	mReturnHover.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage("MenuImages/b_main_menu_glow.png"));

	mCurrentReturn = &mReturnToMainMenuTexture;

	mMenuSprite.setTexture(mMenuTexture);
	mMenuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));

	mReturnToMainMenuSprite.setTexture(mReturnToMainMenuTexture);

	mReturnToMainMenuSprite.setTexture		(mReturnToMainMenuTexture);
	mReturnToMainMenuSprite.setPosition		(mMenuSprite.getPosition() + sf::Vector2f(760, 480));
	mReturnToMainMenuTexRect.setTexture		(mReturnToMainMenuTexture);
	mReturnToMainMenuTexRect.setTextureRect	(sf::IntRect(760, 480, 400, 120));

}