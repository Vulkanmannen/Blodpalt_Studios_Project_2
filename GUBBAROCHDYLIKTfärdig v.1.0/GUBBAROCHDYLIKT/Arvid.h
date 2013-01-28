#ifndef ARVID_H
#define ARVID_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Clock.hpp>

#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>

#include "Animation.h"
#include "Entity.h"
#include <memory>
#include "Flower.h"

class ResourceHandler;

class Arvid : public Entity
{
public:
	Arvid(sf::Vector2f &position);
	~Arvid();

	void update();
	void render(sf::RenderWindow &window);

	void onCollision(Entity *e, sf::FloatRect &result);

private:
	void move();
	void walk();
	void jump();
	void dontJump();
	void jumping();
	void fall();
	void falling();

	void plantFlower(Flower::GrowthDir g);
	void flowerDirection();

	void updateHUD();

	Animation mIdleLeftAnimation;
	Animation mIdleRightAnimation;
	Animation mRunLeftAnimation;
	Animation mRunRightAnimation;
	Animation mJumpRightAnimation;
	Animation mJumpLeftAnimation;
	Animation mAirborneLeftAnimation;
	Animation mAirborneRightAnimation;
	Animation mWaterRightAnimation;
	Animation mWaterLeftAnimation;

	Animation* mCurrentAnimation;

	sf::Vector2f	mMovementSpeed;
	float			mRunSpeed;
	bool			mJumping;
	bool			mFalling;
	float			mJumpDecrease;
	float			mFallAcc;
	int				mJumpTime;
	float			mLove;
	bool			mRunLeft;
	bool			mPlanting;
	int				mCountdown;

	Flower* mFlower;

	sf::Clock	mClock;
	sf::Texture	mLoveBarTexture;
	sf::Sprite	mLoveBarSprite;
	sf::FloatRect	mLoveBarRect;

	sf::Texture	mLoveTexture;
	sf::Sprite	mLoveSprite;
	
	sf::Sound		mWaterSound;
	sf::Sound		mJumpSound;
	
};

#endif