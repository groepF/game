#include "GameState.h"

/*void GameState::onCreate(Event *event)
{
	Log::debug("OnCreate GameState");

	event->playMusic("background");

	world = new World();

	// Kijk hieronder voor mooie level code.
	// Todo: LevelBuilder die levels in elkaar zet.
	// Todo: Render alleen items die op het zichtbaar zijn op het scherm.

	int a[10][20] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	for (auto x = 0; x < 20; x++)
	{
		for (auto y = 0; y < 10; y++)
		{
			if (a[y][x] == 1)
			{
				if (x == 0)
				{
					world->add(new Block(x * 70, y * 70, LEFT));
					continue;
				}
				if (x == 19)
				{
					world->add(new Block(x * 70, y * 70, RIGHT));
					continue;
				}
				if (a[y][x - 1] == 1 && a[y][x + 1] == 1)
				{
					world->add(new Block(x * 70, y * 70, CENTER));
					continue;
				}

				if (a[y][x - 1] == 0)
				{
					world->add(new Block(x * 70, y * 70, LEFT));
					continue;
				}

				if (a[y][x + 1] == 0)
				{
					world->add(new Block(x * 70, y * 70, RIGHT));
				}
			}
		}
	}

	player = new Player(100, 100);
	world->follow(player);
	world->add(player);
}*/

void GameState::onCreate(Event *event)
{
	b2Vec2 gravity(0.0f, 9.81f);
	world = new b2World(gravity);
	body = new Body(*world, 5.0f, 10.0f, 1.0f, 1.0f);
	ball = new Ball(*world, 5.0f, 0.0f, 0.5f, 0.5f);
}

void GameState::onRender(Screen *screen)
{
	body->render(screen);
	ball->render(screen);
}

void GameState::onUpdate(Event *event)
{
	float32 timeStep = 1.0f / 60.0f;	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	world->Step(timeStep, velocityIterations, positionIterations);
}

void GameState::onDestroy()
{
	Log::debug("OnDestroy GameState");
	delete world;
	delete body;
	delete ball;
}