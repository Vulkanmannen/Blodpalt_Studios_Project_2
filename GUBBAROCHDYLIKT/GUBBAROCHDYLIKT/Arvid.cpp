#include "Arvid.h"
#include "ResourceHandler.h"
#include <SFML\Window\Keyboard.hpp>

static sf::Texture TEXTURE;
static sf::Sprite SPRITE;

Arvid::Arvid(sf::Vector2f &position) /*:
	mIdleLeftAnimation	("", 0, 0),
	mIdleRightAnimation ("", 0, 0),
	mRunLeftAnimation	("", 0, 0),
	mRunRightAnimation	("", 0, 0),
	mJumpAnimation		("", 0, 0)*/
{ 
	mEntityKind = ARVID;
	setPosition(position);
	mTexture.loadFromFile("GUBBJEVEL.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(position);
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
	SPRITE.setPosition(getPosition());
}

void Arvid::render(sf::RenderWindow &window)
{
	window.draw(mSprite);
}

void Arvid::onCollision()
{

}