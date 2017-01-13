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
	void setWorld(World* world);

	int getTeamAGoals();
	int getTeamBGoals();

	int getTimeRemaining() const;

	int getElapsedTime() const;

	void teamAScored();

	void teamBScored();

	bool hasWinner() const;

	void ballPossessionCheat();

	std::chrono::system_clock::time_point getTimeLimit();

	void pauseGame();
	void restartGame();

	void endGame();

	bool isOvertime;
	int ballPossessionTeamA;
	int ballPossessionTeamB;
	bool playing = false;

private:
	//Settings
	int gameTime; //Default 180(seconden)
	int maxGoals;
	float gravity;
	char* map;
	std::chrono::system_clock::time_point beginTime;
	std::chrono::system_clock::time_point timeLimit;
	std::chrono::system_clock::time_point startPause;

	int firstGoalTime;

	int goalsTeamA;
	int goalsTeamB;

	

	World *world;
	Player *player;
	Enemy *ai;
	Ball *ball;
	
	const float WORLD_GRAVITY = 9.81f;
};

