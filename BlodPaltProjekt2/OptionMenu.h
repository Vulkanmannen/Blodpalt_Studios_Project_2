#ifndef INCLUDED_OPTIONMENU
#define INCLUDED_OPTIONMENU

#include "MenuState.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

class Super;

class OptionMenu : public MenuState
{
public:
	OptionMenu();
	virtual ~OptionMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mBackTexture;
	sf::Sprite  mBackSprite;
};

#endif