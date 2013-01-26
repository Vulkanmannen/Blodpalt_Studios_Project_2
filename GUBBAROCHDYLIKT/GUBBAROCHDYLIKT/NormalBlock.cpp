#include "NormalBlock.h"
#include "ResourceHandler.h"

static sf::Texture TEXTURE;
static sf::Sprite SPRITE;

NormalBlock::NormalBlock(sf::Vector2f position)
{
	setPosition(position);
	mEntityKind = EntityKind::NORMALBLOCK;
	mTexture.loadFromFile("BLOCK.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(position);
}

NormalBlock::~NormalBlock()
{
}

void NormalBlock::update()
{
	SPRITE.setPosition(getPosition());
}

void NormalBlock::render(sf::RenderWindow &window)
{
	window.draw(mSprite);
}