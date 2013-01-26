#include "EntityManager.h"
#include "Entity.h"

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

void EntityManager::update()
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		mEntityVector[i]->update();
	}
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
			isColliding(mEntityVector[i], mEntityVector[j]);
		}
	}
}

void EntityManager::isColliding(Entity *e1, Entity *e2)
{
	/*if(e1->getHitBox().intersects(e2->getHitBox()))
	{

	}

	else if()
	{
	}

	else if()
	{
	}

	else if()
	{
	}

	else if()
	{
	}

	else if()
	{
	}*/
}
