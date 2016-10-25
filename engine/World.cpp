#include "World.h"



World::World()
{
	b2Vec2 gravity(0.0f, 9.8f);
	_world = new b2World(gravity);


	//_world->CreateBody();
}


World::~World()
{
}

void World::Add(const GameObject gameObject)
{
	
	b2Body* body =_world->CreateBody(gameObject.Def());

	_objects.push_back(body);
}

void World::Step(float timeStep, int velIter, int posIter)
{
	_world->Step(timeStep, velIter, posIter);

}
