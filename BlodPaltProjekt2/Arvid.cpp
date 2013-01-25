#include "Arvid.h"

#include <SFML\Window\Keyboard.hpp>

Arvid::Arvid() 
{ 
	mEntityKind = ARVID; 
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

}

void Arvid::onCollision()
{

}