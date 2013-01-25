#ifndef INCLUDED_INTROSCREEN
#define INCLUDED_INTROSCREEN

#include "MenuState.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>

class Super;
class ImageManager;


class IntroScreen : public MenuState
{
public:
	IntroScreen();
	virtual ~IntroScreen();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();
	
private:
	sf::Texture m_menuTexture;
	sf::Sprite m_menuSprite;
	sf::Clock m_menuClock;
};

#endif
