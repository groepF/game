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
	for (float x = 0; x < reader.getLevelHeight(); x++)
	{
		for (float y = 0; y < reader.getLevelWidth(); y++)
		{
			if (tiles.at(counter) != 0)
			{
				//Retrieve the correct Tile from the TileSet
				std::shared_ptr<Sprite> sprite = tileSet.at(tiles.at(counter)-1);
				
				//Add the sprite to the world
				world->add(new Body(sprite, (size * 2.0f) * y + 0.2f, (size * 2.0f) * x + 0.2f, size, size));
			}
			counter++;
		}
	}

	player = new Player((size * 2) * 3 + 0.2f, (size * 2) * 1 + 0.2f);
	ai = new Enemy((size * 2) * 61 + 0.2f, (size * 2) * 1 + 0.2f);
	ball = new Ball((size * 2) * 32 + 0.2f, (size * 2) * 1 + 0.2f);
	world->add(player);
	world->add(ai);
	world->add(ball);
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
	if (ball->isHeldBy(player)) { ball->pickUp(player); }
	else if (ball->isHeldBy(ai)) { ball->pickUp(ai); }

	if (!keyboard->isKeydown(KEY_A) && !keyboard->isKeydown(KEY_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}
	if (keyboard->isKeydown(KEY_W)) { player->jump(); }
	if (keyboard->isKeydown(KEY_A)) { player->setPlayerState(PLAYER_LEFT); }
	if (keyboard->isKeydown(KEY_D)) { player->setPlayerState(PLAYER_RIGHT); }
	if (keyboard->isKeydown(KEY_F)) { showingFPS = !showingFPS; }
	if (keyboard->isKeydown(KEY_SPACE)) { if (player->canPickup(ai)) ai->hitByPlayer(ball); }
	if (keyboard->isKeydown(KEY_LCTRL)) { if(player->canPickup(ball) || ball->isHeldBy(player)) ball->pickUp(player); }
	if (keyboard->isKeydown(KEY_LEFT)) { if (ball->isHeldBy(player)) ; }
	if (keyboard->isKeydown(KEY_RIGHT)) { if (ball->isHeldBy(player)); }
	if (keyboard->isKeydown(KEY_DOWN)) { if (ball->isHeldBy(player)) ball->drop(); }
	
	//Cheat, give ball to AI
	if (keyboard->isKeydown(KEY_RCTRL)) { ball->pickUp(ai); }
	//Cheat, get hit by AI
	if (keyboard->isKeydown(KEY_RETURN)) { player->hitByEnemy(ball); }


	if(keyboard->isKeydown(KEY_ESCAPE)){/*pause game and show menu*/}

	player->move();
	world->update();
}

void GameState::onDestroy()
{
	delete world;
	Log::debug("OnDestroy GameState");
}