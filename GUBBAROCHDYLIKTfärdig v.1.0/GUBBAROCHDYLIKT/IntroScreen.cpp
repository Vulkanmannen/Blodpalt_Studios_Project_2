#include "IntroScreen.h"
#include "Super.h"
#include "MainMenu.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>


//Constructor, running the initialization function
IntroScreen::IntroScreen()
{
	//mVideo.load("INTRO.ogg");
	//mVideo.setPosition(sf::Vector2f(-960, -540 ) );
	//mMusic.openFromFile("1.0GardenGnome-Intro.ogg");
	//mMusic.play();
	//init();
}


IntroScreen::~IntroScreen()
{
}

////Update function that handles keyboard integration with menu
void IntroScreen::update(Super &r_super)
{
	/*mVideo.update(mVideoClock.restart() );*/


	if(mMenuClock.getElapsedTime().asSeconds() > 30 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
	{
		//mMusic.stop();
		//r_super.getStateManager().popState();
		//r_super.getStateManager().pushState(new MainMenu());
	}

}

//Draw menu sprites on display
void IntroScreen::draw(Super &r_super) 
{
	
	//r_super.getWindow().draw(mVideo);
}

//Assigning a texture to a sprite
//Restarts the stopwatch
void IntroScreen::init()
{
	mMenuTexture.loadFromImage( *ResourceHandler::getInstance()->loadImage("MenuImages/bgb.png"));
	mMenuSprite.setTexture(mMenuTexture);
	mMenuSprite.setPosition(Super::getInstance()->getView().getCenter() - sf::Vector2f(960, 540));

	mMenuClock.restart();
}
