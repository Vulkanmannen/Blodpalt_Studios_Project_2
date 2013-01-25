#include "Entity.h"


Entity::Entity()
	{}


Entity::~Entity()
	{}


sf::FloatRect Entity::getHitBox()const
{
	return mHitBox;
}

sf::Vector2f Entity::getPosition()const
{
	return sf::Vector2f(mHitBox.left, mHitBox.top);
}