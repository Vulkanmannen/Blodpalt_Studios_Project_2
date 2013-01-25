#ifndef INCLUDED_LEVELMENU
#define INCLUDED_LEVELMENU

#include "MenuState.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
class Super;
class GameState;
class LevelManager;
class ImageManager;

class LevelMenu : public MenuState
{
public:
	LevelMenu();
	virtual ~LevelMenu();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:
	//LevelVector m_levelVector;
	//sf::Texture m_menuTexture;
	//sf::Sprite m_menuSprite;

	//sf::Sprite m_level1;
	//sf::Sprite m_level2;

	//sf::Texture m_goldCoinTexture;
	//sf::Sprite m_goldCoinSprite;

};

#endif