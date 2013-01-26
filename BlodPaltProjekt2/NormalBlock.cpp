#include "NormalBlock.h"
#include "ResourceHandler.h"

static sf::Texture TEXTURE;
static sf::Sprite SPRITE;

NormalBlock::NormalBlock(sf::Vector2f position)
{
	setPosition(position);
	mEntityKind = EntityKind::NORMALBLOCK;
	TEXTURE.loadFromFile("BLOCK.png");
	SPRITE.setTexture(TEXTURE);
	SPRITE.setPosition(position);
}

void NormalBlock::update()
{
}

void NormalBlock::render()
{
	ResourceHandler::render(SPRITE);
}