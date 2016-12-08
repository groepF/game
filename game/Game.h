#pragma once
#include "engine/world/World.h"
#include "game/entities/Player.h"
#include "game/entities/Ball.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();

	char* getMap();
	World* getWorld();
	Player* getPlayer();
	Enemy* getEnemy();
	Ball* getBall();


private:
	World *world;
	Player *player;
	Enemy *ai;
	Ball *ball;
	char* map;
	const float WORLD_GRAVITY = 9.81f;
};

