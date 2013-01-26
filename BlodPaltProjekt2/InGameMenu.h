#ifndef INCLUDED_INGAMEMENU
#define INCLUDED_INGAMEMENU

#include "MenuState.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Super;
class ImageManager;
class LevelMenu;

class InGameMenu : public MenuState
{
public:
	InGameMenu();
	virtual ~InGameMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mResumeTexture;
	sf::Sprite  mResumeSprite;

	sf::Texture mOptionTexture;
	sf::Sprite  mOptionSprite;

	sf::Texture  mReturnToMainMenuTexture;
	sf::Sprite  mReturnToMainMenuSprite;
};

#endif