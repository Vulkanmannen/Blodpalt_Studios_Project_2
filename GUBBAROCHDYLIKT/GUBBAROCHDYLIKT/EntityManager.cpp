#include "EntityManager.h"
#include "Entity.h"
#include "Arvid.h"

EntityManager* EntityManager::sInstance = 0;

EntityManager* EntityManager::getInstance()
{
	if(sInstance == 0)
	{
		sInstance = new EntityManager();
	}

	return sInstance;
}

EntityManager::EntityManager()
	{}


EntityManager::~EntityManager()
{
	clear();
}


void EntityManager::addEntity(Entity *e)
{
	mEntityVector.push_back(e);
}

Entity* EntityManager::getArvid()
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		if(mEntityVector[i]->getEntityKind() == Entity::ARVID)
		{
			return mEntityVector[i];
		}
	}
}

void EntityManager::update()
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		mEntityVector[i]->update();
	}
	checkCollisions();
}

void EntityManager::render(sf::RenderWindow &window)
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		mEntityVector[i]->render(window);
	}
}

void EntityManager::clear()
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		if(!mEntityVector[i]->isActive())
		{
			delete mEntityVector[i];
			mEntityVector[i] = mEntityVector.back();
			mEntityVector.pop_back();
		}
	}
}

void EntityManager::checkCollisions()
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		for(EntityVector::size_type j = 0; j < mEntityVector.size(); ++j)
		{
			if(mEntityVector[i]->getEntityKind() == Entity::ARVID && mEntityVector[j]->getEntityKind() != Entity::ARVID)
			{
				ifEntitiesColliding(mEntityVector[i], mEntityVector[j]);
			}
		}
	}
}

void EntityManager::ifEntitiesColliding(Entity *e1, Entity *e2)
{
	sf::FloatRect result;
	float xDif = e1->getHitBox().left - e2->getHitBox().left;
	float yDif = e1->getHitBox().top - e2->getHitBox().top;

	if(e1->getHitBox().intersects(e2->getHitBox(), result))
	{
		if(result.height > result.width)
		{
			if(xDif > 0)
			{
				e1->setPosition(sf::Vector2f(e1->getHitBox().left + result.width, e1->getHitBox().top));
			}
			else
			{
				e1->setPosition(sf::Vector2f(e1->getHitBox().left - result.width, e1->getHitBox().top));
			}
		}
		else
		{
			if(yDif > 0)
			{
				if(result.width > 10)
				{
					e1->setPosition(sf::Vector2f(e1->getHitBox().left, e1->getHitBox().top + result.height));
					e1->onCollision(e2);
				}
			}
			else
			{
				if(result.width > 10)
				{
					e1->setPosition(sf::Vector2f(e1->getHitBox().left, e1->getHitBox().top - result.height));
					e1->onCollision(e2);
				}
			}
		}
	}
}