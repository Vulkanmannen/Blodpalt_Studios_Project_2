#include "LevelClear.h"
#include "Super.h"
#include "MainMenu.h"
#include "ResourceHandler.h"
#include "LoadingState.h"

#include <SFML\Window\Mouse.hpp>

//Constructor, running the initialization function
LevelClear::LevelClear(unsigned int levelJustClear) :
mNextLevel( levelJustClear + 1)
	
{
	mPressed = false;
	init();
	Super::getInstance()->playMusic("win");
}


LevelClear::~LevelClear()
{
}

void LevelClear::buttonAnimation(Super &r_super)
{
	mContinueSprite.setTexture(*mCurrentResume);
	mReturnToMainMenuSprite.setTexture(*mCurrentReturn);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(mContinueTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentResume = &mResumeHover;
	}
	else
		mCurrentResume = &mContinueTexture;

	if(mReturnToMainMenuTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentReturn = &mReturnHover;
	}
	else
		mCurrentReturn = &mReturnToMainMenuTexture;
}

void LevelClear::update(Super &r_super)
{
	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mPressed )
	{
		
		if(mContinueTexRect.getTextureRect().contains(mousePos))
		{
			LoadingState load(mNextLevel);
			load.loadLevel();
			r_super.getInstance()->getStateManager().popState();
			Super::getInstance()->playMusic("level");
		}

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
void LevelClear::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mContinueSprite);
	r_super.getWindow().draw(mReturnToMainMenuSprite);
}

//Assigning a texture to a sprite
//if there is a menu button, a sub sprite. To allow that you can 
//press this button, we give this a position
void LevelClear::init()
{
	mMenuTexture.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage("MenuImages/b_ingame_menu_backdrop.png"));
	mContinueTexture.loadFromImage		  ( *ResourceHandler::getInstance()->loadImage("MenuImages/continue.png"));
	mReturnToMainMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0002_main-menu.png"));
																						
	mResumeHover.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage("MenuImages/continue_glow.png"));
	mReturnHover.loadFromImage			  ( *ResourceHandler::getInstance()->loadImage("MenuImages/b_main_menu_glow.png"));


	mCurrentResume = &mContinueTexture;
	mCurrentReturn = &mReturnToMainMenuTexture;

	mMenuSprite.setTexture(mMenuTexture);
	mMenuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));
	

	mContinueSprite.setTexture				(mContinueTexture);
	mContinueSprite.setPosition				(mMenuSprite.getPosition() + sf::Vector2f(760, 330));
	mContinueTexRect.setTexture				(mContinueTexture);
	mContinueTexRect.setTextureRect			(sf::IntRect(760, 330, 400, 120));

	mReturnToMainMenuSprite.setTexture(mReturnToMainMenuTexture);

	mReturnToMainMenuSprite.setTexture		(mReturnToMainMenuTexture);
	mReturnToMainMenuSprite.setPosition		(mMenuSprite.getPosition() + sf::Vector2f(760, 480));
	mReturnToMainMenuTexRect.setTexture		(mReturnToMainMenuTexture);
	mReturnToMainMenuTexRect.setTextureRect	(sf::IntRect(760, 480, 400, 120));

}