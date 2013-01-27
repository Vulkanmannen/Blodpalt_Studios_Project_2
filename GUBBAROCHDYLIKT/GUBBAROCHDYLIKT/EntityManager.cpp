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

bool EntityManager::lookForBlock(sf::Vector2f &position)
{
	for(EntityVector::size_type i = 0; i < mEntityVector.size(); ++i)
	{
		if(mEntityVector[i]->getEntityKind() == Entity::NORMALBLOCK)
		{
			if(mEntityVector[i]->getHitBox().contains(position))
			{
				return true;
			}
		}
	}
	return false;
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
	for(EntityVector::size_type i = 0; i < mDynamicEntityVector.size(); ++i)
	{
		if(!mDynamicEntityVector[i]->isActive())
		{
			for(EntityVector::size_type j = 0; j < mEntityVector.size(); ++j)
			{
				if(mEntityVector[j] == mDynamicEntityVector[i])
				{
					mEntityVector[j] = mEntityVector.back();
					mEntityVector.pop_back();
				}
			}
			delete mDynamicEntityVector[i];
			mDynamicEntityVector[i] = mEntityVector.back();
			mDynamicEntityVector.pop_back();
		}
	}
}

void EntityManager::checkCollisions()
{
	for(EntityVector::size_type i = 0; i < mDynamicEntityVector.size(); ++i)
	{
		for(EntityVector::size_type j = 0; j < mEntityVector.size(); ++j)
		{
			ifEntitiesColliding(mDynamicEntityVector[i], mEntityVector[j]);
		}
	}
}

void EntityManager::ifEntitiesColliding(Entity *e1, Entity *e2)
{
	if(e1 != e2)
	{
		Entity::EntityKind e1Kind = e1->getEntityKind();
		Entity::EntityKind e2Kind = e2->getEntityKind();

		if(	e1Kind == Entity::ARVID ||
			e1Kind == Entity::ENEMY && e2Kind == Entity::FLOWER || e1Kind == Entity::ENEMY && e2Kind == Entity::NORMALBLOCK ||
			e1Kind == Entity::FLOWER && e2Kind == Entity::NORMALBLOCK || 
			e1Kind == Entity::PUSHABLEBLOCK && e2Kind == Entity::FLOWER || e1Kind == Entity::PUSHABLEBLOCK && e2Kind == Entity::NORMALBLOCK || e1Kind == Entity::PUSHABLEBLOCK && e2Kind == Entity::PUSHABLEBLOCK
			)
		{
			sf::FloatRect result;

			if(e1->getHitBox().intersects(e2->getHitBox(), result))
			{
				e1->onCollision(e2,result);
			}
		}
	}
}