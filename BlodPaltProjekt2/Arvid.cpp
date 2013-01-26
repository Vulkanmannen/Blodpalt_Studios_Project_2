#include "Arvid.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>

static sf::Texture TEXTURE;
static sf::Sprite SPRITE;

Arvid::Arvid(sf::Vector2f &position) :
	mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("", 0, 0),
	mRunLeftAnimation	("", 0, 0),
	mRunRightAnimation	("", 0, 0),
	mJumpAnimation		("", 0, 0)
{ 
	mEntityKind = ARVID;
	setPosition(position);
	TEXTURE.loadFromFile("GUBBJEVEL.png");
	SPRITE.setTexture(TEXTURE);
	mHitBox.width = SPRITE.getLocalBounds().width;
	mHitBox.height = SPRITE.getLocalBounds().height;
	SPRITE.setPosition(mHitBox.left, mHitBox.top);
}

Arvid::~Arvid(){ }


void Arvid::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	
	}
}

void Arvid::render()
{
	ResourceHandler::getInstance()->render(SPRITE);
}

void Arvid::onCollision()
{

}