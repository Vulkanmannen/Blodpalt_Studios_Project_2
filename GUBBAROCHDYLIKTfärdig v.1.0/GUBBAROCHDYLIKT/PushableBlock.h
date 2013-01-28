#pragma once
#include "block.h"
class PushableBlock : public Block
{
public:
	PushableBlock(sf::Vector2f &position);
	~PushableBlock();

	///////////////////////////////////////////////////////
	// /Does nothing
	///////////////////////////////////////////////////////
	void update();
	///////////////////////////////////////////////////////
	// /Draws the block
	///////////////////////////////////////////////////////
	void render(sf::RenderWindow &window);

	void onCollision(Entity *e, sf::FloatRect &result);
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mNormalCount;
};

