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
class Flower;

class Arvid : public Entity
{
public:
	Arvid(sf::Vector2f &position);
	~Arvid();

	void update();
	void render(sf::RenderWindow &window);

	void onCollision(Entity *e);

private:
	void move();
	void walk();
	void jump();
	void dontJump();
	void jumping();
	void fall();
	void falling();

	void plantFlower();

	/*Animation mIdleLeftAnimation;
	Animation mIdleRightAnimation;
	Animation mRunLeftAnimation;
	Animation mRunRightAnimation;
	Animation mJumpAnimation;

	Animation* mCurrentAnimation;*/

	sf::Vector2f	mMovementSpeed;
	float			mRunSpeed;
	bool			mJumping;
	bool			mFalling;
	float			mJumpDecrease;
	float			mFallAcc;
	int				mJumpTime;
	int				mLove;

	Flower* mFlower;

	sf::Clock	mClock;
	sf::Texture	mTexture;
	sf::Sprite	mSprite;
};

#endif