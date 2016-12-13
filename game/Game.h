#pragma once
#include "engine/world/World.h"
#include "game/entities/Player.h"
#include "game/entities/Ball.h"
#include "game/entities/Enemy.h"
#include "chrono"


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

	void begin();

	void setTime(int minutes);
	void setGoals(int goals);
	void setMap(int id);

	int getTeamAGoals();
	int getTeamBGoals();

	int getTimeRemaining();

	std::chrono::system_clock::time_point getTimeLimit();

	bool isOvertime;

private:
	//Settings
	int gameTime; //Default 180(seconden)
	int maxGoals;
	float gravity;
	char* map;
	std::chrono::system_clock::time_point beginTime;
	std::chrono::system_clock::time_point timeLimit;

	int goalsTeamA;
	int goalsTeamB;

	World *world;
	Player *player;
	Enemy *ai;
	Ball *ball;
	
	const float WORLD_GRAVITY = 9.81f;
};

