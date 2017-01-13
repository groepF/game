#include "GameState.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"
#include "../map/LevelReader.h"
#include "../../engine/core-entities/FpsCounter.h"
#include "../entities/Score.h"
#include "../../engine/core-entities/DrawableEntity.h"
#include "../entities/Timer.h"
#include "MenuState.h"
#include "../../engine/widgets/Label.h"
#include "PauseState.h"


GameState::GameState(StateContext* context, Game* game) : State(context),
world(nullptr),
player(nullptr),
isDebug(Config::getBool("debug", false)),
showGrid(false)
{
	this->game = game;
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

	/*world = new World(WORLD_GRAVITY);
	game->setWorld(world);*/
	this->fpsCounter = new FpsCounter();

	world = game->getWorld();
	player = game->getPlayer();
	player2 = game->getPlayer2();
	ball = game->getBall();

	if (!this->game->playing)
	{
		game->begin();
	}
	LevelReader reader(game->getMap());
	//Get Datalayer Tiles and TileSet Tiles
	auto tiles = reader.getTiles();
	auto tileSet = reader.getTileSet();

	//Set Background.
	auto background = new Sprite("background", 0, 0, 1300, 720);
	world->addBackground(background);

	int counter = 0;
	for (float x = 0; x < reader.getLevelHeight(); x++)
	{
		for (float y = 0; y < reader.getLevelWidth(); y++)
		{
			if (tiles.at(counter) != 0)
			{
				//Retrieve the correct Tile from the TileSet
				std::shared_ptr<Sprite> sprite = tileSet.at(tiles.at(counter) - 1);

				//Add the sprite to the world
				world->add(new DrawableEntity(sprite, (game->getSize() * 2.0f) * y + 0.2f, (game->getSize() * 2.0f) * x + 0.2f, game->getSize(), game->getSize()));
			}
			counter++;
		}
	}

	player=  game->getPlayer();
	player2 = game->getPlayer2();
	ball = game->getBall();

	fpsCounter = new FpsCounter(true, 1200);

	//Add the player, ball and AI to the world
	world->add(player);
	world->add(player2);

	world->add(fpsCounter);
	world->add(new Score(game));
	world->add(new Timer(game));
	world->add(ball);

	player->setFixedRotation(true);
	player2->setFixedRotation(true);

}

void GameState::onRender(Screen *screen)
{
	fpsCounter->CalculateCurrentFps();
	if (showHybricGrid)
	{
		showGrid = !showGrid;
	}
	world->render(screen, showGrid);
}

void GameState::onUpdate(Keyboard *keyboard)
{
	if (keyboard->isKeydown(KEY_ESCAPE))
	{
		context->setState(new PauseState(context, game));
		return;
	}

	if (game->getTimeRemaining() <= 0 && !game->isOvertime)
	{
		game->isOvertime = true;
		game->teamAScored();
		game->teamAScored();
		game->teamAScored();
		if (game->hasWinner()) {
			game->endGame();
			context->setState(new MenuState(context));
			return;
		}
	}

	if (ball->isHeldBy(player2))
	{
		game->ballPossessionTeamB++;
	}
	if (ball->isHeldBy(player))
	{
		game->ballPossessionTeamA++;
	}

	if (ball->isHeldBy(player)) { ball->pickUp(player); }
	else if (ball->isHeldBy(player2)) { ball->pickUp(player2); }

	if (keyboard->isKeydown(KEY_F)) { fpsCounter->toggle(); }
	if (keyboard->isKeydown(KEY_F1) && isDebug) { showGrid = !showGrid; showHybricGrid = false; }
	if (keyboard->isKeydown(KEY_F2) && isDebug) { showHybricGrid = !showHybricGrid;; showGrid = false; }
	if (!keyboard->isKeydown(KEY_A) && !keyboard->isKeydown(KEY_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}
	if (keyboard->isKeydown(KEY_W)) { player->jump(); }
	if (keyboard->isKeydown(KEY_A)) { player->setPlayerState(PLAYER_LEFT); }
	if (keyboard->isKeydown(KEY_D)) { player->setPlayerState(PLAYER_RIGHT); }
	if (keyboard->isKeydown(KEY_SPACE)) { if (player->canPickup(player2)) player2->hitByPlayer(ball); }
	if (keyboard->isKeydown(KEY_LCTRL)) { if (player->canPickup(ball) || ball->isHeldBy(player)) ball->pickUp(player); }
	if (keyboard->isKeydown(KEY_LEFT)) { if (ball->isHeldBy(player)) { ball->drop(); ball->shoot(player, true); } }
	if (keyboard->isKeydown(KEY_RIGHT)) { if (ball->isHeldBy(player)) { ball->drop(); ball->shoot(player, false); } }
	if (keyboard->isKeydown(KEY_DOWN)) { if (ball->isHeldBy(player)) ball->drop(); }
	//Cheat, give ball to AI
	if (keyboard->isKeydown(KEY_RCTRL)) { ball->pickUp(player2); }
	//Cheat, get hit by AI
	if (keyboard->isKeydown(KEY_RETURN)) { player->hitByEnemy(ball); }




	// TODO: call Game.teamAScored and Game.teamBScored when someone scored

	player->move();
	world->update();
}

void GameState::onDestroy()
{
	//delete world;
	Log::debug("OnDestroy GameState");
}