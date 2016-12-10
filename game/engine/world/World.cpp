#include "World.h"

World::World(float gravity) : world(nullptr), background(nullptr)
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
	if (background)
	{
		delete background;
		background = nullptr;
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
		body->Render(*screen);
	}
}

void World::add(Body* body)
{
	auto item = world->CreateBody(body->getBodyDef());
	body->create(item);
	body->setDefaultRenderStrategy();
	bodies.push_back(body);
}

void World::addBackground(Sprite* background)
{
	this->background = background;
}