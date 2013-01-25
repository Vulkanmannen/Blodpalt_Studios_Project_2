#ifndef INCLUDED_ENTITYMANAGER
#define INCLUDED_ENTITYMANAGER

class Entity;

class EntityManager
{
public:
	static EntityManager* getInstance();

	~EntityManager();
	void update();
	void render();

	void addEntity(Entity* e);
private:
	EntityManager();
	EntityManager(const EntityManager&);
	const void operator=(const EntityManager);

	static EntityManager* sInstance;

	void checkCollisions();
	void isColliding(Entity *e1, Entity *e2);

};

#endif