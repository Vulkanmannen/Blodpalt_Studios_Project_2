#include "Animation.h"
#include "ResourceHandler.h"


Animation::Animation(const std::string &fileName, int timePerFrame, int numberOfFrames) :
		mTimePerFrame(timePerFrame),
		mNumberOfFrames(numberOfFrames),

		mCurrentAnimation(0),
		mEndOfAnimation(false)
{
	mTexture.loadFromImage(*ResourceHandler::getInstance()->loadImage(fileName));
	
	mSprite.setTexture(mTexture);
	sf::IntRect textureRect(0, 0, mTexture.getSize().x / mNumberOfFrames, mTexture.getSize().y);
	mSprite.setTextureRect(textureRect);
	mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
}

Animation::~Animation() {}

//
void Animation::update()
{
	
	if(mFrameTimer.getElapsedTime().asMilliseconds() > mTimePerFrame)
	{
		mFrameTimer.restart();
		mCurrentAnimation++;

		if(mCurrentAnimation >= mNumberOfFrames)
		{
			mEndOfAnimation = true;
			mCurrentAnimation = 0; 
		}
		else
		{
			mEndOfAnimation = false;
		}
		
		sf::IntRect currentRect = mSprite.getTextureRect();
		currentRect.left = currentRect.width * mCurrentAnimation;
		mSprite.setTextureRect(currentRect);
	}
}


void Animation::setPosition(const sf::Vector2f &position)
{
	mSprite.setPosition(position);
}


const sf::Sprite& Animation::getSprite() const
{
	return mSprite;
}


bool Animation::endOfAnimation()
{
	return mEndOfAnimation;
}