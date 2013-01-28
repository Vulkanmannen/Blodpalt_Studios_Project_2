#include "HowToPlayMenu.h"
#include "ResourceHandler.h"
#include "Super.h"

#include <SFML\Window\Mouse.hpp>

HowToPlayMenu::HowToPlayMenu()
{
	mPressed = false;
	init();
}

HowToPlayMenu::~HowToPlayMenu()
{
}

void HowToPlayMenu::buttonAnimation(Super &r_super)
{
	mBackSprite.setTexture(*mCurrentBack);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());

	if(mBackTexRect.getTextureRect().contains(mousePos))
	{
		mCurrentBack = &mBackHover;
	}
	else
		mCurrentBack = &mBackTexture;
}

void HowToPlayMenu::update(Super &r_super)
{
	buttonAnimation(r_super);

	sf::Vector2i mousePos = sf::Mouse::getPosition(r_super.getWindow());
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mPressed)
	{
		if(mBackTexRect.getTextureRect().contains(mousePos))
		{
			r_super.getStateManager().popState();
		}
		mPressed = false;
	}
	if( !sf::Mouse::isButtonPressed(sf::Mouse::Left) )
		mPressed = true;
}

void HowToPlayMenu::draw(Super &r_super) 
{
	r_super.getWindow().draw(mMenuSprite);
	r_super.getWindow().draw(mHowToS);
	r_super.getWindow().draw(mBackSprite);
}

void HowToPlayMenu::init()
{
	mMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/bgb.png")); 
	mBackTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0001_back.png"));

	mHowToT.loadFromImage	  ( *ResourceHandler::getInstance()->loadImage("MenuImages/how_to.png"));

	mBackHover.loadFromImage  ( *ResourceHandler::getInstance()->loadImage("MenuImages/BUTTONS_0001_back_glow.png"));
	mMenuSprite.setTexture(mMenuTexture);
	mHowToS.setTexture(mHowToT);
	mHowToS.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(540, 200));
	mMenuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));
	
	mCurrentBack = &mBackTexture;

	mBackSprite.setTexture(mBackTexture);
	mBackSprite.setPosition(mMenuSprite.getPosition() + sf::Vector2f(760, 900));
	mBackTexRect.setTexture(mBackTexture);
	mBackTexRect.setTextureRect(sf::IntRect(760, 900 , 400, 120));
}