#ifndef INCLUDED_MAINMENU
#define INCLUDED_MAINMENU

#include "MenuState.h"
#include "Animation.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

class Super;
class OptionMenu;
class LevelMenu;
class GameState;
class ImageManager;

class MainMenu : public MenuState
{
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mPlayTexture;
	sf::Sprite  mPlaySprite;

	sf::Texture mOptionTexture;
	sf::Sprite  mOptionSprite;

	sf::Texture mHowToPlayTexture;
	sf::Sprite  mHowToPlaySprite;

	sf::Texture mQuitTexture;
	sf::Sprite  mQuitSprite;
};

#endif