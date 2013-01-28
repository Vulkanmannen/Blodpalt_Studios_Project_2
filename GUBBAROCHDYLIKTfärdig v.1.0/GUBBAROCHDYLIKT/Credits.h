#ifndef INCLUDED_CREDTIS
#define INCLUDED_CREDTIS

#include "MenuState.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Super;
class ImageManager;
class LevelMenu;

class Credits : public MenuState
{
public:
	Credits();
	virtual ~Credits();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:

	void buttonAnimation(Super &r_super);

	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mReturnToMainMenuTexture;
	sf::Sprite  mReturnToMainMenuSprite;
	sf::Sprite  mReturnToMainMenuTexRect;

	sf::Texture mReturnHover;

	sf::Texture *mCurrentReturn;
};

#endif