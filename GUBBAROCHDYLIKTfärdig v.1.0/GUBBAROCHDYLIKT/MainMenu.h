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
	void buttonAnimation(Super &r_super);
	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mPlayTexture;
	sf::Sprite  mPlaySprite;
	sf::Sprite  mPlayTexRect;

	sf::Texture mPlayHover;


	sf::Texture mHowToPlayTexture;
	sf::Sprite  mHowToPlaySprite;
	sf::Sprite  mHowToPlayTexRect;

	sf::Texture mHowToPlayHover;

	sf::Texture mQuitTexture;
	sf::Sprite  mQuitSprite;
	sf::Sprite  mQuitTexRect;

	sf::Texture mQuitHover;


	sf::Texture *mCurrentPlay;
	sf::Texture *mCurrentHowTo;
	sf::Texture *mCurrentQuit;

};



#endif