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
	void buttonAnimation(Super &r_super);
	//sf::Texture m_menuTexture;
	//sf::Sprite m_menuSprite;

	//sf::Texture m_resumeTexture;
	//sf::Texture m_chooseTexture;
	//sf::Texture m_optionsTexture;
	//sf::Texture m_mainMenuTexture;
	//sf::Sprite m_resumeSprite;
	//sf::Sprite m_chooseSprite;
	//sf::Sprite m_optionsSprite;
	//sf::Sprite m_mainMenuSprite;

	//sf::Texture m_resumeTextureHover;
	//sf::Texture m_chooseTextureHover;
	//sf::Texture m_optionsTextureHover;
	//sf::Texture m_mainMenuTextureHover;

	//sf::Texture m_resumeTextureClick;
	//sf::Texture m_chooseTextureClick;
	//sf::Texture m_optionsTextureClick;
	//sf::Texture m_mainMenuTextureClick;

	//sf::Sprite m_resumeTextRect;
	//sf::Sprite m_chooseTextRect;
	//sf::Sprite m_optionsTextRect;
	//sf::Sprite m_mainMenuTextRect;

	//sf::Texture *m_currentResumeTexture;
	//sf::Texture *m_currentChooseTexture;
	//sf::Texture *m_currentOptionsTexture;
	//sf::Texture *m_currentMainMenuTexture;
};

#endif