#pragma once

#include <vector>
#include <Box2D/Box2D.h>
#include "../core/Entity.h"
#include "../graphics/Screen.h"
#include "../util/Config.h"
#include "Body.h"
#include "ContactListener.h"

class World
{
public:
	World(Game* game, float gravity = 9.81f);
	~World();

	void update() const;
	void render(Screen *screen, const bool debug = false);
	void add(Body * body, std::string id = "");
	void addBackground(Sprite* s);

	void setContactListener(ContactListener* listener);
private:
	b2World *world;
	ContactListener* contacts;
	std::vector<Body*> bodies;
	Sprite* background;

};
