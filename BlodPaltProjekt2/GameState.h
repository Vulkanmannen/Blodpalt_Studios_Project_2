#ifndef INCLUDED_GAMESTATE
#define INCLUDED_GAMESTATE

#include "State.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <vector>

class Manager;
class InGameMenu;
class Super;


class GameState : public State
{
public:
	typedef std::vector<sf::Sprite*> BackgroundVector;

	GameState();
	~GameState();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;

	void init(); 

private:
	//BackgroundVector m_backgroundVector;

	//
	//void createBackground();
	//void updateBackground();
	//void drawBackground(Super &r_super);

	//void checkClosestSquare();
	//int getSquare(sf::Vector2f square);
	//void changeMidSquare(int newMid);
	//void moveBackground();

	//Manager* manager;
	//sf::Texture m_backgroundShadowTexture;
	//sf::Sprite m_backgroundShadowSprite;

	//sf::Texture m_backgroundTexture;
};

#endif