#ifndef INCLUDED_FLOWER
#define INCLUDED_FLOWER

#include "Entity.h"
#include <SFML\System\Clock.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Animation.h"
#include <memory>

class Animation;
class Flower : public Entity
{
public:
	enum GrowthDir{
		HORIZONTAL, VERTICAL
	};
	Flower(sf::Vector2f position, bool growleft, GrowthDir dir = VERTICAL);
	~Flower();

	void update();
	void render(sf::RenderWindow &window);
	void onCollision(Entity *e, sf::FloatRect &result);

	void grow();
	void isNotGrowing();

	GrowthDir getGrowthDir();

	static void init();
private:
	unsigned int mLifeTime; //Lifetime, in frames.
	bool mIsGrowing;
	bool mGrowLeft;
	GrowthDir mGrowthDir;

	Animation mFlowerAnimation;
	Animation mIdleAnimation;
	Animation mDyingAnimation;

	Animation *mCurrentAnimation;

	std::shared_ptr<sf::Texture> mFlowerTex;
	sf::Sprite mSprite;
};
//48 X 128 PX

#endif