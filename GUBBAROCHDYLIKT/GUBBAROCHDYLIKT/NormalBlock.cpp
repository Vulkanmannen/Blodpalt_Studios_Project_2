#include "NormalBlock.h"
#include "ResourceHandler.h"


NormalBlock::NormalBlock(sf::Vector2f position)
{
	setPosition(position);
	mEntityKind = EntityKind::NORMALBLOCK;
	mTexture.loadFromFile("block_grass_jord.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(position);
	mHitBox = sf::FloatRect(position, sf::Vector2f(64, 64));
}

NormalBlock::~NormalBlock()
{
}

void NormalBlock::update()
{
	mSprite.setPosition(getPosition());
}

void NormalBlock::render(sf::RenderWindow &window)
{
	window.draw(mSprite);
}