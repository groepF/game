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

/**
* Function gets called when state changes
*/
void GameState::onCreate()
{
	Log::debug("OnCreate GameState");

	this->fpsCounter = std::make_unique<FpsCounter>(FpsCounter());

	world = new World(WORLD_GRAVITY);

	LevelReader reader("res/maps/level1.tmx");
	//Get Datalayer Tiles and TileSet Tiles
	auto tiles = reader.getTiles();
	auto tileSet = reader.getTileSet();
	
	auto background = new Sprite("background", 0, 0, 1300, 720);
	world->addBackground(background);
	auto size = 0.2f;
	int counter = 0;
	for (int x = 0; x < reader.getLevelHeight(); x++)
	{
		for (auto y = 0; y < reader.getLevelWidth(); y++)
		{
			if (tiles.at(counter) != 0)
			{
				//Retrieve the correct Tile from the TileSet
				std::shared_ptr<Sprite> sprite = tileSet.at(tiles.at(counter)-1);
				
				//Add the sprite to the world
				world->add(new Body(sprite, (size * 2) * y, (size * 2) * x, size, size));
			}
			counter++;
		}
	}

	//auto playerLoc = reader.getPlayerLocation();
	// Log::debug(std::to_string(playerLoc.at(0)));

	player = new Player((size * 2) * 2, (size * 2) * 1);
	ai = new Enemy((size * 2) * 62, (size * 2) * 1);
	ball = new Ball((size * 2) * 32, (size * 2) * 1);
	world->add(player);
	world->add(ball);
	world->add(ai);
	player->setFixedRotation(true);
	ai->setFixedRotation(true);
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
	if (keyboard->isKeydown(KEY_LCTRL)) { if(player->canPickup(ball) || ball->isHeldBy(player)) ball->pickUp(player); }
	else if (!keyboard->isKeydown(KEY_LCTRL))
	{
		if(keyboard->isKeydown(KEY_LEFT)) { /*SHOOT LEFT*/ }
		if(keyboard->isKeydown(KEY_RIGHT)) { /* SHOOT RIGHT */ }
		ball->drop();
	}
	

	player->move();
	world->update();
}

void GameState::onDestroy()
{
	delete world;
	Log::debug("OnDestroy GameState");
}