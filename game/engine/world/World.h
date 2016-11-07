#pragma once

#include <vector>
#include "../core/Entity.h"
#include "../graphics/Screen.h"
#include "../util/Config.h"

class World
{
public:
	World();
	~World();

	void update(float delta);
	void render(Screen *screen);

	void add(Entity *entity);
	void follow(Entity *entity);

private:
	std::vector<Entity*> entities;
	Entity *following;
	int cameraX, cameraY;
};