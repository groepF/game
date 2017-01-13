#include "GameState.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"
#include "../map/LevelReader.h"
#include "../../engine/core-entities/FpsCounter.h"
#include "../entities/Score.h"
#include "../../engine/core-entities/DrawableEntity.h"
#include "../entities/Timer.h"
#include "MenuState.h"
#include "../../engine/location/Graph.h"
#include "../entities/EndGameStats.h"
#include "TransitionState.h"


GameState::GameState(StateContext* context, Game* game) : State(context),
world(nullptr),
player(nullptr),
isDebug(Config::getBool("debug", false)),
showGrid(false)
{
	this->game = game;
	this->game->begin();
	this->endGameScreenSeconds = 4;
	this->throwForce = 50;
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

	world = new World(WORLD_GRAVITY);

	this->fpsCounter = new FpsCounter();

	world = game->getWorld();
	player = game->getPlayer();
	player2 = game->getPlayer2();
	ball = game->getBall();

	p1LastDirection = RIGHT;
	p2LastDirection = LEFT;

	LevelReader reader(game->getMap());

	//Graph ophalen
	Graph* graph = game->getGraph();

	//Get Datalayer Tiles and TileSet Tiles
	auto tiles = reader.getTiles();
	auto tileSet = reader.getTileSet();

	//Set Background.
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
				std::shared_ptr<Sprite> sprite = tileSet.at(tiles.at(counter) - 1);

				//Add the sprite to the world
				world->add(new DrawableEntity(sprite, (size * 2.0f) * y + 0.2f, (size * 2.0f) * x + 0.2f, size, size));
			}
			counter++;
		}
	}

	player = new Player((size * 2) * 3, (size * 2) * 1);
	player2 = new Player((size * 2) * 61, (size * 2) * 1);
	ball = new Ball((size * 2) * 32, (size * 2) * 1);
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
	if (game->gameOver)
	{
		// keep the score on screen for a couple of seconds.
		int past_seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - game->gameEnded).count();
		if (past_seconds >= endGameScreenSeconds)
		{
			context->setState(new TransitionState(context));
		}
		return;
	}

	if (game->getTimeRemaining() <= 0 && game->hasWinner() || game->getTeamAGoals() >= game->getGoalLimit() || game->getTeamBGoals() >= game->getGoalLimit()) {
		game->endGame();
		world->add(new EndGameStats(game));
		return;
	}


	if (game->getTimeRemaining() <= 0 && !game->isOvertime)
	{
		// tmp to foce winner
		game->teamAScored();
		game->teamAScored();
		game->teamAScored();
		// end tmp
		game->isOvertime = true;
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

	// player 1
	if (!keyboard->isKeydown(KEY_A) && !keyboard->isKeydown(KEY_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}

	// TMP CHEAT
	if (keyboard->isKeydown(KEY_SPACE))
	{
		ball->pickUp(player);
	}
	if (keyboard->isKeydown(KEY_W)) { player->jump(); p1LastDirection = UP; }
	if (keyboard->isKeydown(KEY_A)) { player->setPlayerState(PLAYER_LEFT); p1LastDirection = LEFT; }
	if (keyboard->isKeydown(KEY_D)) { player->setPlayerState(PLAYER_RIGHT); p1LastDirection = RIGHT; }
	if (keyboard->isKeydown(KEY_E)) {
		if (player->isInRangeOf(ball) && !ball->isHeldBy(player)) { ball->pickUp(player); }
		else if (ball->isHeldBy(player)) { ball->drop(); }
		else if (player->isInRangeOf(player2)) player2->hitByEnemy(ball);
	}

	if (keyboard->isKeydown(KEY_LSHIFT))
	{
		double p1xforce = 0;
		double p1yforce = 0;
		if (keyboard->isKeydown(KEY_W)) p1yforce += throwForce;
		if (keyboard->isKeydown(KEY_S)) p1yforce -= throwForce;
		if (keyboard->isKeydown(KEY_D)) p1xforce += throwForce;
		if (keyboard->isKeydown(KEY_A)) p1xforce -= throwForce;

		if (p1xforce == 0 && p1yforce == 0)
		{
			switch (p1LastDirection)
			{
			case UP:
				p1yforce += throwForce;
			case DOWN:
				p1yforce -= throwForce;
			case RIGHT:
				p1xforce += throwForce;
			case LEFT:
				p1xforce -= throwForce;
			default: break;
			}
		}
		if (ball->isHeldBy(player)) { ball->drop(); ball->shoot(player, p1xforce, -p1yforce); }
	}

	//player 2
	if (!keyboard->isKeydown(KEY_LEFT) && !keyboard->isKeydown(KEY_RIGHT))
	{
		player2->setPlayerState(PLAYER_STOP);
	}
	if (keyboard->isKeydown(KEY_UP)) { player2->jump(); p2LastDirection = UP; }
	if (keyboard->isKeydown(KEY_LEFT)) { player2->setPlayerState(PLAYER_LEFT); p2LastDirection = LEFT; }
	if (keyboard->isKeydown(KEY_RIGHT)) { player2->setPlayerState(PLAYER_RIGHT); p2LastDirection = RIGHT; }

	if (keyboard->isKeydown(KEY_RCTRL)) {
		if (player2->isInRangeOf(ball) && !ball->isHeldBy(player2)) { ball->pickUp(player2); }
		else if (ball->isHeldBy(player2)) { ball->drop(); }
		else if (player2->isInRangeOf(ball)) player->hitByEnemy(ball);
	}

	if (keyboard->isKeydown(KEY_RSHIFT))
	{
		double p2xforce = 0;
		double p2yforce = 0;
		if (keyboard->isKeydown(KEY_UP)) p2yforce += throwForce;
		if (keyboard->isKeydown(KEY_DOWN)) p2yforce -= throwForce;
		if (keyboard->isKeydown(KEY_RIGHT)) p2xforce += throwForce;
		if (keyboard->isKeydown(KEY_LEFT)) p2xforce -= throwForce;

		if (p2xforce == 0 && p2yforce == 0)
		{
			switch (p1LastDirection)
			{
			case UP:
				p2yforce += throwForce;
			case DOWN:
				p2yforce -= throwForce;
			case RIGHT:
				p2xforce += throwForce;
			case LEFT:
				p2xforce -= throwForce;
			default: break;
			}
		}
		if (ball->isHeldBy(player2)) { ball->drop(); ball->shoot(player2, p2xforce, -p2yforce); }

	}

	//cheats
	if (Config::getBool("debug", false))
	{
		//toggle sprite boundary view
		if (keyboard->isKeydown(KEY_F1)) { showGrid = !showGrid; showHybricGrid = false; }
		//toggle hybrid view
		if (keyboard->isKeydown(KEY_F2)) { showHybricGrid = !showHybricGrid;; showGrid = false; }
		//player 1 scoren
		if (keyboard->isKeydown(KEY_F3)) { game->teamAScored(); }
		//player 2 scoren
		if (keyboard->isKeydown(KEY_F4)) { game->teamBScored(); }
		//player 1 win
		if (keyboard->isKeydown(KEY_F5)) {}
		//player 2 win
		if (keyboard->isKeydown(KEY_F6)) {}
		//time remaining omlaag
		if (keyboard->isKeydown(KEY_F7)) { game->changeTimeRemaining(-10); }
		//time remaining omhoog
		if (keyboard->isKeydown(KEY_F8)) { game->changeTimeRemaining(10); }
		//speler 1 100% balbezit
		if (keyboard->isKeydown(KEY_F9)) { game->ballPossessionCheat(true); }
		//speler 2 100% balbezit
		if (keyboard->isKeydown(KEY_F10)) { game->ballPossessionCheat(false); }
		//spel versnellen
		if (keyboard->isKeydown(KEY_F11)) {}
		//spel vertragen
		if (keyboard->isKeydown(KEY_F12)) {}
	}


	// TODO: call Game.teamAScored and Game.teamBScored when someone scored

	player->move();
	player2->move();
	world->update();
}

void GameState::onDestroy()
{
	delete world;
	Log::debug("OnDestroy GameState");
}