#include "World.h"

#define PPM 50

World::World(float gravity) : world(nullptr)
{
	b2Vec2 vec(0.0f, gravity);
	world = new b2World(vec);
}

World::~World()
{
	if (world)
	{
		delete world;
		world = nullptr;
	}
	for (const auto &body : bodies)
	{
		delete body;
	}
	bodies.clear();
}

void World::update() const
{
	world->Step(1.0f / 60.0f, 8, 3);
}

void World::render(Screen* screen, const bool debug)
{
	//teken background
	screen->render(this->background,
		(screen->getWidth() / 2) - (this->background->getWidth() / 2),
		(screen->getHeight() / 2) - (this->background->getHeight() / 2),
		0);

	for (const auto &body : bodies)
	{
		if (debug)
		{
			screen->renderRect((body->getX() * PPM) - ((body->getWidth() * PPM) / 2), (body->getY() * PPM) - ((body->getHeight() * PPM) / 2), body->getWidth() * PPM, body->getHeight() * PPM);
		}
		else
		{
			screen->render(body->getSprite(),
				(body->getX() - (body->getWidth() / 2)) * PPM,
				(body->getY() - (body->getHeight() / 2)) * PPM,
				body->getAngle(),
				255, body->getWidth() * PPM, body->getHeight() * PPM);
		}
	}
}

void World::add(Body* body)
{
	auto item = world->CreateBody(body->getBodyDef());
	body->create(item);

	bodies.push_back(body);
}

void World::addBackground(Sprite* background)
{
	this->background = background;
}