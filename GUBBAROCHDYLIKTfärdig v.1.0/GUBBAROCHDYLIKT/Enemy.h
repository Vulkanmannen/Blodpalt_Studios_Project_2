#pragma once
#include "Entity.h"
#include "Animation.h"
#include <string>

enum EnemyType{ALEX, JON};

class Enemy : public Entity
{
public:
	Enemy(sf::Vector2f &position, EnemyType type);
	~Enemy();

	void update();
	void render(sf::RenderWindow &window);
	void onCollision(Entity *e, sf::FloatRect &result);

	void changeDirection();

	sf::Vector2f getPoint();
private:
	void move();

	float mMovementSpeed;

	Animation mLeftAnimation;
	Animation mRightAnimation;

	Animation *mCurrentAnimation;

	EnemyType mEnemyType;

	sf::Vector2f mEdgeCheck;
	bool mWalkLeft;
};

