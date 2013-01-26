#ifndef ARVID_H
#define ARVID_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Clock.hpp>

#include "Animation.h"
#include "Entity.h"
#include <memory>

class ResourceHandler;

class Arvid : public Entity
{
public:
	Arvid();
	~Arvid();

	void update();
	void render();

	void onCollision();

private:
	void move();

	Animation mIdleLeftAnimation;
	Animation mIdleRightAnimation;
	Animation mRunLeftAnimation;
	Animation mRunRightAnimation;
	Animation mJumpAnimation;

	Animation* mCurrentAnimation;

	sf::Clock mClock;
};

#endif