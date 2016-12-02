#include "GameState.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"
#include "../map/LevelReader.h"
#include "../../engine/Entities/FpsCounter.h"

GameState::GameState(StateContext* context) :
	State(context),
	world(nullptr),
	player(nullptr),
	showingFPS(true)
{
}

GameState::~GameState()
{

}

void GameState::onCreate()
{
	Log::debug("OnCreate GameState");

	this->fpsCounter = new FpsCounter();

	world = new World(WORLD_GRAVITY);

	LevelReader reader("res/maps/level1.tmx");
	auto tiles = reader.getTiles();
	auto tileSet = reader.getTileSet();
	
	auto background = new Sprite("background", 0, 0, 1300, 720);
	world->addBackground(background);

	int counter = 0;
	for (int x = 0; x < reader.getLevelHeight(); x++)
	{
		for (auto y = 0; y < reader.getLevelWidth(); y++)
		{
			if (tiles.at(counter) != 0)
			{
				std::shared_ptr<Sprite> sprite = tileSet.at(tiles.at(counter)-1);
				auto size = 0.2f;
				world->add(new Body(*sprite, (size * 2) * y, (size * 2) * x, size, size));
			}
			counter++;
		}
	}

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