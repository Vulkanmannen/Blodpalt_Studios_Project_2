#include "Goal.h"


Goal::Goal(sf::Vector2f &position)
	{
		mLayer =  MIDDLE;
		setPosition(position);
		mEntityKind = EntityKind::GOAL;
		mTexture.loadFromFile("goal.png");
		mSprite.setTexture(mTexture);
		mSprite.setPosition(position);
		mHitBox = sf::FloatRect(position, sf::Vector2f(64, 64));
	}


Goal::~Goal()
	{}

void Goal::render(sf::RenderWindow &window)
{
	window.draw(mSprite);
}