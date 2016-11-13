#include "GameState.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"

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
	Log::debug("OnCreate GameState");

	world = new World(9.81f);
	event->playMusic("background");

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
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	for (auto x = 0; x < 20; x++)
	{
		for (auto y = 0; y < 10; y++)
		{
			if (a[y][x] == 1)
			{
				auto size = 0.5f;
				world->add(new Body((size * 2) * x, (size * 2) * y, size, size));
			}
		}
	}

	player = new Player(1.0f, 1.0f);
	world->add(player);
	world->add(new Ball(5.0f, 5.0f));
}

void GameState::onRender(Screen *screen)
{
	world->render(screen, false);
}

void GameState::onUpdate(Event *event)
{
	if (!event->isKeydown(KEY_A) && !event->isKeydown(KEY_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}
	if (event->isKeydown(KEY_W)) { player->jump(); }
	if (event->isKeydown(KEY_A)) { player->setPlayerState(PLAYER_LEFT); }
	if (event->isKeydown(KEY_D)) { player->setPlayerState(PLAYER_RIGHT); }
	player->move();
	world->update();
}

void GameState::onDestroy()
{
	delete world; 
	Log::debug("OnDestroy GameState");
}