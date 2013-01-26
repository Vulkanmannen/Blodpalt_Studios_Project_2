#ifndef INCLUDED_ENTITYMANAGER
#define INCLUDED_ENTITYMANAGER

#include <SFML\Graphics\RenderWindow.hpp>
#include <memory>
#include <vector>

class Entity;

class EntityManager
{
public:
	typedef std::vector<Entity*> EntityVector;
	static EntityManager* getInstance();

	~EntityManager();
	void update();
	void render(sf::RenderWindow &window);

	void addEntity(Entity* e);
	void clear();

private:
	EntityManager();
	EntityManager(const EntityManager&);
	const void operator=(const EntityManager);

	EntityVector mEntityVector;

	static EntityManager* sInstance;

	void checkCollisions();
	void ifEntitiesColliding(Entity *e1, Entity *e2);


};

#endif