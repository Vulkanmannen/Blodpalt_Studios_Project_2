#include "Entity.h"


Entity::Entity()
	{}


Entity::~Entity()
	{}

bool Entity::isActive()const
{
	return mIsActive;
}

sf::Vector2f Entity::getPosition()const
{
	return sf::Vector2f(mHitBox.left, mHitBox.top);
}

Entity::EntityKind Entity::getEntityKind()const
{
	return mEntityKind;
}

void Entity::setPosition(sf::Vector2f &position)
{
	mHitBox.left = position.x;
	mHitBox.top = position.y;
}

sf::FloatRect Entity::getHitBox()const
{
	return mHitBox;
}