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
/*	sf::Texture m_menuTexture;
	sf::Sprite m_menuSprite;

	sf::Texture m_chooseTexture;
	sf::Texture m_optionsTexture;
	sf::Texture m_howToPlayTexture;
	sf::Texture m_quitTexture;
	sf::Sprite m_chooseSprite;
	sf::Sprite m_optionsSprite;
	sf::Sprite m_howToPlaySprite;
	sf::Sprite m_quitSprite;

	sf::Texture m_chooseTextureHover;
	sf::Texture m_optionsTextureHover;
	sf::Texture m_howToPlayTextureHover;
	sf::Texture m_quitTextureHover;

	sf::Texture m_chooseTextureClick;
	sf::Texture m_optionsTextureClick;
	sf::Texture m_howToPlayTextureClick;
	sf::Texture m_quitTextureClick;

	sf::Sprite m_chooseTextRect;
	sf::Sprite m_optionsTextRect;
	sf::Sprite m_howToPlayTextRect;
	sf::Sprite m_QTextRect;

	sf::Texture *m_currentChooseTexture;
	sf::Texture *m_currentOptionsTexture;
	sf::Texture *m_currentHowToTexture;
	sf::Texture *m_currentQuitTexture*/;
};

#endif