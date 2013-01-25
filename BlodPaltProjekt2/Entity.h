#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

#include "SFML\Graphics.hpp"

class Entity
{
public:
	enum EntityKind {ARVID, FLOWER, BLOCK, ENEMY, MOVINGBLOCK};

	Entity();
	~Entity();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onCollision(Entity *e) = 0;

	// getfunktioner
	sf::FloatRect getHitBox()const;
	bool isActive()const;
	sf::Vector2f getPosition()const;
	EntityKind getEntityKind()const;

	// setfunktioner
	void setPosition(sf::Vector2f &position);
	void setNotActive();

protected:
	virtual sf::Sprite getSprite()const;
	sf::FloatRect mHitBox;

	bool isActive;
	EntityKind mEntityKind;
};

#endif