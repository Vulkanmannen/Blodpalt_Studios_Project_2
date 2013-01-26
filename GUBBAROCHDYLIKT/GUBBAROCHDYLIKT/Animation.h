#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\System\Vector2.hpp>
#include <string>

class Animation
{
public:
	Animation(const std::string &fileName, int timePerFrame, int frameCount);
	~Animation();

	void update();
	void setPosition(const sf::Vector2f &position);
	const sf::Sprite& getSprite() const;
	bool endOfAnimation();

	void resetFrameCount();


private:
	int mCurrentFrame;
	int mTimePerFrame;
	int mNumberOfFrames;
	bool mEndOfAnimation;

	sf::Clock mFrameTimer;
	sf::Texture mTexture;
	sf::Sprite mSprite;
};

#endif