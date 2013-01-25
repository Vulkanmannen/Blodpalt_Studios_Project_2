#ifndef INCLUDED_OPTIONMENU
#define INCLUDED_OPTIONMENU

#include "MenuState.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

class Super;
class ImageManager;

class OptionMenu : public MenuState
{
public:
	OptionMenu();
	virtual ~OptionMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	void buttonAnimation(Super &r_super);

	//sf::Texture m_menuTexture;
	//sf::Sprite m_menuSprite;

	//sf::Texture m_backTexture;
	//sf::Sprite m_backSprite;

	//sf::Texture m_backTextureHover;
	//sf::Sprite m_backSpriteHover;

	//sf::Sprite m_backTextureRect;

	//sf::Texture *m_currentBackTexture;
};

#endif