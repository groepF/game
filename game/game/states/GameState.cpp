#include "GameState.h"
#include "../map/LevelReader.h"
#include "../entities/Score.h"
#include "../entities/Timer.h"
#include "PauseState.h"
#include "TransitionState.h"
#include "../entities/EndGameStats.h"
#include "../entities/PossessionMeter.h"

GameState::GameState(StateContext* context, Game* game) : State(context),
world(nullptr),
player(nullptr),
isDebug(Config::getBool("debug", false)),
showGrid(false)
{
	this->game = game;
	this->endGameScreenSeconds = 4;
	this->throwForce = 50;
	this->gameSpeed = 0.0f;
}

GameState::~GameState()
{
}

void GameState::setGameStateItems()
{
	world = game->getWorld();
	player = game->getPlayer();
	player2 = game->getPlayer2();
	ball = game->getBall();

	p1LastDirection = RIGHT;
	p2LastDirection = LEFT;
}

void GameState::populateWord()
{
	world = new World(game, WORLD_GRAVITY);
	game->setWorld(world);

	setGameStateItems();

	LevelReader reader(game->getMap());

	//Graph ophalen
	Graph* graph = game->getGraph();

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

				if (tiles.at(counter) == 7)
				{
					world->add(new DrawableEntity(sprite, (game->getSize() * 2.0f) * y + 0.2f, (game->getSize() * 2.0f) * x + 0.2f, game->getSize(), game->getSize()), "red_goal");
				} 
				else if (tiles.at(counter) == 8)
				{
					world->add(new DrawableEntity(sprite, (game->getSize() * 2.0f) * y + 0.2f, (game->getSize() * 2.0f) * x + 0.2f, game->getSize(), game->getSize()), "blue_goal");
				}
				else
				{
					world->add(new DrawableEntity(sprite, (game->getSize() * 2.0f) * y + 0.2f, (game->getSize() * 2.0f) * x + 0.2f, game->getSize(), game->getSize()));
				}
			}
			counter++;
		}
	}



	//Add the player, ball and AI to the world


	world->add(player);
	world->add(player2);

	world->add(new Score(game));
	world->add(new Timer(game));
	world->add(ball);

	player->setUserData("player1");
	player2->setUserData("player2");
	ball->setUserData("ball");

	player->setFixedRotation(true);
	player2->setFixedRotation(true);
}

void GameState::createFpsCounter()
{
	fpsCounter = new FpsCounter(true, 1200);
	world->add(fpsCounter);
}

void GameState::createPossessionMeter() const
{
	world->add(new TextualEntity("possession", 75, 683, 100, 50, Color("black"), "Ball possession"));
	world->add(new PossessionMeter("p1possession", PossessionMeter::PLAYER1, this->game, 230, 683, 100, 50, Color("red")));
	world->add(new PossessionMeter("p2possession", PossessionMeter::PLAYER2, this->game, 280, 683, 100, 50, Color("blue")));
}

/**
* Function gets called when state changes
*/
void GameState::onCreate()
{
	Log::debug("OnCreate GameState");
	if (!this->game->playing)
	{
		game->begin();
		populateWord();
	}
	else
	{
		setGameStateItems();
	}
	createFpsCounter();
	createPossessionMeter();
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
	if(game->scored == true)
	{
		if(!ball->scoreAnimation())
		{
			game->scored = false;
		}
	}

	if (keyboard->isKeyPressed(SDL_SCANCODE_ESCAPE))
	{
		context->setState(new PauseState(context, game));
		return;
	}

	if (game->gameOver)
	{
		// keep the score on screen for a couple of seconds.
		int past_seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - game->gameEnded).count();
		if (past_seconds >= endGameScreenSeconds)
		{
			context->setState(new TransitionState(context, game));
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
		game->isOvertime = true;
	}

	game->calculateBallPossession();

	if (ball->isHeldBy(player)) { ball->pickUp(player); }
	else if (ball->isHeldBy(player2)) { ball->pickUp(player2); }


	if (keyboard->isKeyPressed(SDL_SCANCODE_F)) { fpsCounter->toggle(); }

	// player 1
	if (!keyboard->isKeyHeld(SDL_SCANCODE_A) && !keyboard->isKeyHeld(SDL_SCANCODE_D))
	{
		player->setPlayerState(PLAYER_STOP);
	}

	if (keyboard->isKeyHeld(SDL_SCANCODE_W)) { player->jump(); p1LastDirection = UP; }
	if (keyboard->isKeyHeld(SDL_SCANCODE_A)) { player->setPlayerState(PLAYER_LEFT); p1LastDirection = LEFT;  }
	if (keyboard->isKeyHeld(SDL_SCANCODE_D)) { player->setPlayerState(PLAYER_RIGHT); p1LastDirection = RIGHT; }
	if (keyboard->isKeyPressed(SDL_SCANCODE_E)) {
		if (player->isInRangeOf(ball) && !ball->isHeldBy(player)) { ball->pickUp(player); }
		else if (ball->isHeldBy(player)) { ball->drop(); }
		else if (player->isInRangeOf(player2)) player2->hitByEnemy(ball);
	}

	if (keyboard->isKeyPressed(SDL_SCANCODE_LSHIFT))
	{
		double p1xforce = 0;
		double p1yforce = 0;
		if (keyboard->isKeyHeld(SDL_SCANCODE_W)) p1yforce += throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_S)) p1yforce -= throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_D)) p1xforce += throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_A)) p1xforce -= throwForce;

		if (p1xforce == 0 && p1yforce == 0)
		{
			switch (p1LastDirection)
			{
			case UP:
				p1yforce += throwForce;
				break;
			case DOWN:
				p1yforce -= throwForce;
				break;
			case RIGHT:
				p1xforce += throwForce;
				break;
			case LEFT:
				p1xforce -= throwForce;
				break;
			default: break;
			}
		}
		if (ball->isHeldBy(player)) { ball->drop(); ball->shoot(player, p1xforce, -p1yforce); }
	}

	//player 2
	if (!keyboard->isKeyHeld(SDL_SCANCODE_LEFT) && !keyboard->isKeyHeld(SDL_SCANCODE_RIGHT))
	{
		player2->setPlayerState(PLAYER_STOP);
	}
	if (keyboard->isKeyHeld(SDL_SCANCODE_UP)) { player2->jump(); p2LastDirection = UP; }
	if (keyboard->isKeyHeld(SDL_SCANCODE_LEFT)) { player2->setPlayerState(PLAYER_LEFT); p2LastDirection = LEFT; }
	if (keyboard->isKeyHeld(SDL_SCANCODE_RIGHT)) { player2->setPlayerState(PLAYER_RIGHT); p2LastDirection = RIGHT; }

	if (keyboard->isKeyPressed(SDL_SCANCODE_RCTRL)) {
		if (player2->isInRangeOf(ball) && !ball->isHeldBy(player2)) { ball->pickUp(player2); }
		else if (ball->isHeldBy(player2)) { ball->drop(); }
		else if (player2->isInRangeOf(ball)) player->hitByEnemy(ball);
	}

	if (keyboard->isKeyPressed(SDL_SCANCODE_RSHIFT))
	{
		double p2xforce = 0;
		double p2yforce = 0;
		if (keyboard->isKeyHeld(SDL_SCANCODE_UP)) p2yforce += throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_DOWN)) p2yforce -= throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_RIGHT)) p2xforce += throwForce;
		if (keyboard->isKeyHeld(SDL_SCANCODE_LEFT)) p2xforce -= throwForce;

		if (p2xforce == 0 && p2yforce == 0)
		{
			switch (p1LastDirection)
			{
			case UP:
				p2yforce += throwForce;
				break;
			case DOWN:
				p2yforce -= throwForce;
				break;
			case RIGHT:
				p2xforce += throwForce;
				break;
			case LEFT:
				p2xforce -= throwForce;
				break;
			default: break;
			}
		}
		if (ball->isHeldBy(player2)) { ball->drop(); ball->shoot(player2, p2xforce, -p2yforce); }

	}

	//cheats
	if (Config::getBool("debug", false))
	{
		//toggle sprite boundary view
		if (keyboard->isKeyPressed(SDL_SCANCODE_F1)) { showGrid = !showGrid; showHybricGrid = false; }
		//toggle hybrid view
		if (keyboard->isKeyPressed(SDL_SCANCODE_F2)) { showHybricGrid = !showHybricGrid;; showGrid = false; }
		//player 1 scoren
		if (keyboard->isKeyPressed(SDL_SCANCODE_F3)) { game->teamAScored(); }
		//player 2 scoren
		if (keyboard->isKeyPressed(SDL_SCANCODE_F4)) { game->teamBScored(); }
		//player 1 win
		if (keyboard->isKeyPressed(SDL_SCANCODE_F5)) { game->teamAWin(); }
		//player 2 win
		if (keyboard->isKeyPressed(SDL_SCANCODE_F6)) { game->teamBWin(); }
		//time remaining omlaag
		if (keyboard->isKeyPressed(SDL_SCANCODE_F7)) { game->changeTimeRemaining(-10); }
		//time remaining omhoog
		if (keyboard->isKeyPressed(SDL_SCANCODE_F8)) { game->changeTimeRemaining(10); }
		//speler 1 100% balbezit
		if (keyboard->isKeyPressed(SDL_SCANCODE_F9)) { game->ballPossessionCheat(true); }
		//speler 2 100% balbezit
		if (keyboard->isKeyPressed(SDL_SCANCODE_F10)) { game->ballPossessionCheat(false); }
		//spel versnellen
		if (keyboard->isKeyHeld(SDL_SCANCODE_EQUALS))
		{
			if (this->gameSpeed < 0.04f)
			{
				this->gameSpeed += 0.001f;
			}
		}
		//spel vertragen
		if (keyboard->isKeyHeld(SDL_SCANCODE_MINUS))
		{
			if (this->gameSpeed > 0.001f)
			{
				this->gameSpeed -= 0.001f;
			}
		}
		if (gameSpeed != 0.0f)
		{
			world->stepWithSpeed(gameSpeed);
		}
	}

	// TODO: call Game.teamAScored and Game.teamBScored when someone scored

	player->move();
	player2->move();
	world->update();
}

void GameState::onDestroy()
{
	//delete world;
	game->setWorld(world);

	Log::debug("OnDestroy GameState");
}