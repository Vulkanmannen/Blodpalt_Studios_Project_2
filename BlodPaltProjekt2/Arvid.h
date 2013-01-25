#ifndef ARVID_H
#define ARVID_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>

#include "Entity.h"

class Arvid : public Entity
{
public:
	Arvid();
	~Arvid();

	void update();
	void render();

	void onCollision();

private:
	
};

#endif