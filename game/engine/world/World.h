#pragma once

#include <vector>
#include <Box2D/Box2D.h>
#include "../core/Entity.h"
#include "../graphics/Screen.h"
#include "../util/Config.h"
#include "Body.h"

class World
{
public:
	World(float gravity = 9.81f);
	~World();

	void update() const;
	void render(Screen *screen, const bool debug = false);
	void add(Body *body);
	void addBackground(Sprite* s);

private:
	b2World *world;
	std::vector<Body*> bodies;
	Sprite* background;

};