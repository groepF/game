#include "World.h"

World::World(): following(nullptr), cameraX(0), cameraY(0)
{ }

World::~World()
{
	for (auto const& entity : entities) {
		delete entity;
	}
	entities.clear();
}

void World::update(float delta)
{
	if (following != nullptr)
	{
		cameraX += (following->getX() - (Config::getInt("width", 0) / 2) - cameraX) * 7 * delta;
		cameraY += (following->getY() - (Config::getInt("height", 0) / 2) - cameraY) * 7 * delta;
	}

	for (auto const& entity : entities) {
		entity->onUpdate(delta);
	}
}

void World::render(Screen* screen)
{
	for (auto const& entity : entities) {
		screen->render(entity->getSprite(), entity->getX() - cameraX, entity->getY() - cameraY, 0, 1, 255);
	}
}

void World::add(Entity* entity)
{
	entities.push_back(entity);
}

void World::follow(Entity* entity)
{
	following = entity;
}
