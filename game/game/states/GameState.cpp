#include "GameState.h"

void GameState::onCreate(Event *event)
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
}

void GameState::onRender(Screen *screen)
{
	world->render(screen);
}

void GameState::onUpdate(Event *event)
{
	world->update(event->getDelta());

	auto speed = 2;
	auto x = 0, y = 0;

	if (event->isKeydown(KEY_W)) { y -= speed; }
	if (event->isKeydown(KEY_S)) { y += speed; }
	if (event->isKeydown(KEY_A)) { x -= speed; }
	if (event->isKeydown(KEY_D)) { x += speed; }

	player->setPosition(player->getX() + x, player->getY() + y);
}

void GameState::onDestroy()
{
	Log::debug("OnDestroy GameState");
	delete world;
}