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

}


void EntityManager::addEntity(Entity *e)
{
	mEntityVector.push_back(e);
}

void EntityManager::addDynamicEntity(Entity* e)
{
	mEntityVector.push_back(e);
	mDynamicEntityVector.push_back(e);
}

Entity* EntityManager::getArvid()
{
	for(EntityVector::size_type i = 0; i < mDynamicEntityVector.size(); ++i)
	{
		if(mDynamicEntityVector[i]->getEntityKind() == Entity::ARVID)
		{
			return mDynamicEntityVector[i];
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
	deleteInactives();
}

void EntityManager::render(sf::RenderWindow &window)
{
	for(int h = 0; h < 3; ++h)
	{
		for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
		{
			if(mEntityVector[i]->getEntityLayer() == h)
			{
				mEntityVector[i]->render(window);
			}
		}
	}
}

void EntityManager::deleteInactives()
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
	for(EntityVector::size_type i = 0; i < mDynamicEntityVector.size(); ++i)
	{
		for(EntityVector::size_type j = 0; j < mEntityVector.size(); ++j)
		{
			if(mDynamicEntityVector[i]->getEntityKind() == Entity::ARVID && mEntityVector[j]->getEntityKind() != Entity::ARVID)
			{
				ifEntitiesColliding(mDynamicEntityVector[i], mEntityVector[j]);
			}
		}
	}
}

void EntityManager::ifEntitiesColliding(Entity *e1, Entity *e2)
{
	sf::FloatRect result;

	if(e1->getHitBox().intersects(e2->getHitBox(), result))
	{
		e1->onCollision(e2,result);
	}
}