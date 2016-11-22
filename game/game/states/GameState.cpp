#include "GameState.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"
#include "../map/LevelReader.h"
#include "../../engine/Entities/FpsCounter.h"

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

GameState::GameState(StateContext* context) :
	State(context),
	world(nullptr),
	player(nullptr),
	showingFPS(true)
{
}

void GameState::onCreate()
{
	Log::debug("OnCreate GameState");

	this->fpsCounter = new FpsCounter();

	world = new World(WORLD_GRAVITY);

	LevelReader reader("res/maps/level1.tmx");
	auto tiles = reader.getTiles();
	auto background = new Sprite("background", 0, 0, 1300, 720);
	world->addBackground(background);

	int counter = 0;
	for (int x = 0; x < reader.getLevelHeight(); x++)
	{
		for (auto y = 0; y < reader.getLevelWidth(); y++)
		{
			if (tiles.at(counter) != 0)
			{
				Sprite* sprite;
				switch (tiles.at(counter)) {
				case 1:
					sprite = new Sprite("metal", 0, 0, 20, 20);
					break;
				case 2:
					sprite = new Sprite("metal", 20, 0, 20, 20);
					break;
				case 3:
					sprite = new Sprite("metal", 0, 20, 20, 20);
					break;
				case 4:
					sprite = new Sprite("metal", 20, 20, 20, 20);
					break;
				case 5:
					sprite = new Sprite("metal", 0, 40, 20, 20);
					break;
				case 7:
					sprite = new Sprite("teams", 0, 0, 20, 20);
					break;
				case 8:
					sprite = new Sprite("teams", 20, 0, 20, 20);
					break;
				case 9:
					sprite = new Sprite("castle", 0, 0, 20, 20);
					break;
				case 10:
					sprite = new Sprite("castle", 20, 0, 20, 20);
					break;
				case 11:
					sprite = new Sprite("castle", 40, 0, 20, 20);
					break;
				case 12:
					sprite = new Sprite("castle", 0, 20, 20, 20);
					break;
				case 13:
					sprite = new Sprite("castle", 20, 20, 20, 20);
					break;
				case 14:
					sprite = new Sprite("castle", 40, 20, 20, 20);
					break;
				case 15:
					sprite = new Sprite("castle", 0, 40, 20, 20);
					break;
				case 16:
					sprite = new Sprite("castle", 20, 40, 20, 20);
					break;
				case 17:
					sprite = new Sprite("castle", 40, 40, 20, 20);
					break;
				case 18:
					sprite = new Sprite("castle", 0, 60, 20, 20);
					break;
				case 19:
					sprite = new Sprite("castle", 20, 60, 20, 20);
					break;
				case 20:
					sprite = new Sprite("castle", 40, 60, 20, 20);
					break;
				default:
					sprite = new Sprite("metal", 0, 40, 20, 20);
					break;
				}
				auto size = 0.2f;
				world->add(new Body(sprite, (size * 2) * y, (size * 2) * x, size, size));
			}
			counter++;
		}
	}

	/*int a[10][20] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
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
	}*/

	player = new Player(1.0f, 1.0f);
	world->add(player);
	world->add(new Ball(5.0f, 5.0f));
	player->setFixedRotation(true);
}

void GameState::onRender(Screen *screen)
{
	world->render(screen);
	if (showingFPS)
	{
		this->fpsCounter->outputFPS(*screen);
	}
}

void GameState::onUpdate(Keyboard *keyboard)
{
	if (!keyboard->isKeydown(KEY_A) && !keyboard->isKeydown(KEY_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}
	if (keyboard->isKeydown(KEY_W)) { player->jump(); }
	if (keyboard->isKeydown(KEY_A)) { player->setPlayerState(PLAYER_LEFT); }
	if (keyboard->isKeydown(KEY_D)) { player->setPlayerState(PLAYER_RIGHT); }
	if (keyboard->isKeydown(KEY_F)) { showingFPS = !showingFPS; }

	player->move();
	world->update();
}

void GameState::onDestroy()
{
	delete world;
	Log::debug("OnDestroy GameState");
}