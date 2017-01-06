#include "Game.h"


Game::Game()
{
	this->world = new World(WORLD_GRAVITY);

	//Default map
	this->map = "./res/maps/level1.tmx";

	auto size = 0.2f;
	player = new Player((size * 2) * 3, (size * 2) * 1);
	ai = new Enemy((size * 2) * 61, (size * 2) * 1);
	ball = new Ball((size * 2) * 32, (size * 2) * 1);

	//Default settings
	this->gameTime = 3;
	this->maxGoals = 5;

	isOvertime = false;
}


Game::~Game()
{
}

char* Game::getMap()
{
	return this->map;
}

World* Game::getWorld()
{
	return this->world;
}

Player* Game::getPlayer()
{
	return this->player;
}

Enemy* Game::getEnemy()
{
	return this->ai;
}

Ball* Game::getBall()
{
	return this->ball;
}

void Game::begin()
{
	// add a countdown?
	this->goalsTeamA = 0;
	this->goalsTeamB = 0;
	this->ballPossessionTeamA = 0;
	this->ballPossessionTeamB = 0;
	beginTime = std::chrono::system_clock::now();
	timeLimit = beginTime + std::chrono::duration<int>(gameTime * 60);
}

void Game::setTime(int minutes)
{
	gameTime = minutes;
}

void Game::setGoals(int goals)
{
	maxGoals = goals;
}

void Game::setMap(int id)
{
	switch (id)
	{
	case 1:
		this->map = "./res/maps/level1.tmx";
		break;
	case 2:
		this->map = "./res/maps/level2.tmx";
		break;
	case 3:
		this->map = "./res/maps/level3.tmx";
		break;
	default:
		this->map = "./res/maps/level1.tmx";
		break;
	}
}

int Game::getTeamAGoals()
{
	return goalsTeamA;
}

int Game::getTeamBGoals()
{
	return goalsTeamB;
}

int Game::getTimeRemaining()
{
	return std::chrono::duration_cast<std::chrono::seconds>(timeLimit - std::chrono::system_clock::now()).count();
}

std::chrono::system_clock::time_point Game::getTimeLimit()
{
	return timeLimit;
}

void Game::endGame()
{
	// save statistics and highscores, just always call the methods in highscore class
	// highscore class will only save the value if it is better

	// only save ball possession of player A, since this is our player
	int ballPossession = 0;
	if (ballPossessionTeamA == 0 || ballPossessionTeamB == 0)
	{
		if (ballPossessionTeamA == 0 && ballPossessionTeamB == 0)
		{
			ballPossession = 0;
		}
		else if (ballPossessionTeamA > 0)
		{
			ballPossession = 100;
		}
	}
	else if (ballPossessionTeamA > ballPossessionTeamB)
	{
		float a = ballPossessionTeamA;
		float b = ballPossessionTeamB;
		float p = 100.0 - b / a * 100.0;
		ballPossession = round(p);
	}
	else
	{
		float a = ballPossessionTeamA;
		float b = ballPossessionTeamB;
		float p = a / b * 100.0;
		ballPossession = round(p);
	}


}
