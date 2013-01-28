#ifndef INCLUDED_HOWTOPLAYMENU
#define INCLUDED_HOWTOPLAYMENU

#include "MenuState.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Super;
class ImageManager;

class HowToPlayMenu : public MenuState
{
public:
	HowToPlayMenu();
	virtual ~HowToPlayMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	void buttonAnimation(Super &r_super);
	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mHowToT;
	sf::Sprite  mHowToS;

	sf::Texture mBackTexture;
	sf::Sprite	mBackSprite;
	sf::Sprite  mBackTexRect;
	sf::Texture mBackHover;

	sf::Texture *mCurrentBack;
};

#endif