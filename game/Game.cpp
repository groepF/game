#include "Game.h"



Game::Game()
{
	this->world = new World(WORLD_GRAVITY);

	this->map = "./res/maps/level2.tmx";

	auto size = 0.2f;
	player = new Player((size * 2) * 3, (size * 2) * 1);
	ai = new Enemy((size * 2) * 61, (size * 2) * 1);
	ball = new Ball((size * 2) * 32, (size * 2) * 1);
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
