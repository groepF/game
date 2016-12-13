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
	beginTime = std::chrono::system_clock::now();
	timeLimit = beginTime + std::chrono::duration<int>(gameTime*60);
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
