#pragma once

#include "Box2D/Box2D.h"
#include "GameObject.h"
#include <vector>

class World
{
public:
	World();
	~World();

	void Add(const GameObject gameObject);

	void Step(float timeStep, int velIter, int posIter);

private:
	b2World* _world;
	std::vector<b2Body*> _objects;
};