#include "MainMenu.h"
#include "Super.h"
#include "LoadingState.h"
#include "GameState.h"
#include "HowToPlayMenu.h"
#include "ResourceHandler.h"
#include "WorldMapState.h"
#include <SFML\Window\Mouse.hpp>
#include <memory>

//Constructor, running the initialization function
MainMenu::MainMenu()
{
	mPressed = false;
	init();
	Super::getInstance()->playMusic("menu");
}

MainMenu::~MainMenu()
{
}

void MainMenu::buttonAnimation(Super &r_super)
{
	mPlaySprite.setTexture(*mCurrentPlay);
	mHowToPlaySprite.setTexture(*mCurrentHowTo);
	mQuitSprite.setTexture(*mCurrentQuit);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(mPlayTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentPlay = &mPlayHover;
	}
	else 
		mCurrentPlay = &mPlayTexture;

	if(mHowToPlayTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentHowTo = &mHowToPlayHover;
	}
	else
		mCurrentHowTo = &mHowToPlayTexture;

	if(mQuitTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentQuit = &mQuitHover;
	}
	else
		mCurrentQuit = &mQuitTexture;
}

//Update function that handles mouse integration with menu buttons
void MainMenu::update(Super &r_super)
{
	buttonAnimation(r_super);
	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mPressed)
	{
		if(mPlayTexRect.getTextureRect().contains(mousePos))
		{
			//r_super.getStateManager().popState();
			EntityManager::getInstance()->levelClear(0);
			LoadingState load(1);
			load.loadLevel();
			r_super.getStateManager().pushState(new GameState());
		}
		if(mHowToPlayTexRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().pushState(new HowToPlayMenu());
		}
		if(mQuitTexRect.getTextureRect().contains(mousePos))
		{
			r_super.getWindow().close();
		}
		mPressed = false;
	}
	if( !sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		mPressed = true;
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
		//Load textures
	mMenuTexture.loadFromImage      ( *ResourceHandler::getInstance()->loadImage("MenuImages/bgb.png"));
	mPlayTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0002_Group-1.png"));
	mHowToPlayTexture.loadFromImage ( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0001_Group-2.png"));
	mQuitTexture.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0003_Group-3.png"));

	mPlayHover.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0002_Group-1_glow.png"));
	mHowToPlayHover.loadFromImage	( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0001_Group-2_glow.png"));
	mQuitHover.loadFromImage		( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0003_Group-3_glow.png"));
		//Set texturs and positions
	mMenuSprite.setTexture(mMenuTexture);
	mMenuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));

	mCurrentPlay = &mPlayTexture;
	mCurrentHowTo = &mHowToPlayTexture;
	mCurrentQuit = &mQuitTexture;

	mPlaySprite.setTexture			(mPlayTexture);
	mPlaySprite.setPosition			(mMenuSprite.getPosition() + sf::Vector2f(760, 327));
	mPlayTexRect.setTexture			(mPlayTexture);
	mPlayTexRect.setTextureRect		(sf::IntRect(760, 330, 400, 120));

	mHowToPlaySprite.setTexture		(mHowToPlayTexture);
	mHowToPlaySprite.setPosition	(mMenuSprite.getPosition() + sf::Vector2f(760, 480));
	mHowToPlayTexRect.setTexture	(mHowToPlayTexture);
	mHowToPlayTexRect.setTextureRect( sf::IntRect(760, 480, 400, 120));

	mQuitSprite.setTexture			(mQuitTexture);
	mQuitSprite.setPosition			(mMenuSprite.getPosition() + sf::Vector2f(760, 630));
	mQuitTexRect.setTexture         (mQuitTexture);
	mQuitTexRect.setTextureRect		(sf::IntRect(760, 630, 400, 120));
}