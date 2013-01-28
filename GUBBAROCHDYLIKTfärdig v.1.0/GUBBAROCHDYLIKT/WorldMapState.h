#ifndef INCLUDED_WORLDMAPSTATE
#define INCLUDED_WORLDMAPSTATE
#include "MenuState.h"

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class WorldMapState : public MenuState{
public:
	WorldMapState();
	~WorldMapState();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super);

	void init();
private:
	unsigned int  mLocked;

	sf::Texture mMapTexture;
	sf::Sprite  mMapSprite;

	sf::Texture mLevelOneT;
	sf::Sprite  mLevelOneS;
	sf::Sprite mLevelOneRect;

	sf::Texture mLevelTwoT;
	sf::Sprite mLevelTwoS;
	sf::Sprite mLevelTwoRect;

	sf::Texture mLevelThreeT;
	sf::Sprite mLevelThreeS;
	sf::Sprite mLevelThreeRect;
};

#endif