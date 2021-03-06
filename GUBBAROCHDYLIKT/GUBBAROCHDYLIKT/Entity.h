#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

#include "SFML\Graphics.hpp"

class Entity
{
public:
	enum EntityKind {ARVID, FLOWER, NORMALBLOCK, ENEMY, PUSHABLEBLOCK, GOAL};
	enum EntityLayer {BACK, MIDDLE, FRONT};

	Entity();
	virtual ~Entity();
	virtual void update() = 0;
	virtual void render(sf::RenderWindow &window) = 0;
	virtual void onCollision(Entity *e, sf::FloatRect &result){};

	// getfunktioner
	bool			isActive()const;
	sf::Vector2f	getPosition()const;
	EntityKind		getEntityKind()const;
	EntityLayer		getEntityLayer()const;
	sf::FloatRect	getHitBox()const;

	// setfunktioner
	void setPosition(sf::Vector2f &position);
	void setNotActive();

protected:
	sf::FloatRect	mHitBox;
	EntityKind		mEntityKind;
	EntityLayer		mLayer;
	bool			mIsActive;
};

#endif