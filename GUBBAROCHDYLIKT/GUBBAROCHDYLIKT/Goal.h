#ifndef INCLUDED_GOAL
#define INCLUDED_GOAL

#include "Entity.h"

class Goal : public Entity
{
public:
	Goal(sf::Vector2f &position);
	~Goal();

	void update(){};
	void render(sf::RenderWindow &window);
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
};

#endif