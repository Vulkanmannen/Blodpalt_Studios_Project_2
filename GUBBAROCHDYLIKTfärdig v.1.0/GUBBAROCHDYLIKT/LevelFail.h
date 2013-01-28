#ifndef INCLUDED_LEVELFAIL
#define INCLUDED_LEVELFAIL

#include "MenuState.h"
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Super;
class ImageManager;
class LevelMenu;

class LevelFail : public MenuState
{
public:
	LevelFail(unsigned int levelJustClear);
	virtual ~LevelFail();

	virtual void update(Super &r_super);
	virtual void draw(Super &r_super) ;
	
	void init();

private:

	void buttonAnimation(Super &r_super);

	sf::Texture mMenuTexture;
	sf::Sprite  mMenuSprite;

	sf::Texture mContinueTexture;
	sf::Sprite  mContinueSprite;
	sf::Sprite  mContinueTexRect;

	sf::Texture mResumeHover;


	sf::Texture mReturnToMainMenuTexture;
	sf::Sprite  mReturnToMainMenuSprite;
	sf::Sprite  mReturnToMainMenuTexRect;

	sf::Texture mReturnHover;



	sf::Texture *mCurrentResume;
	sf::Texture *mCurrentReturn;

	unsigned int mNextLevel;
};

#endif