#pragma once
#include "engine/world/World.h"
#include "game/entities/Player.h"
#include "game/entities/Ball.h"
#include "game/entities/Enemy.h"
#include "chrono"
#include "engine/location/Graph.h"


class Game
{
public:
	Game();
	~Game();

	char* getMap();
	World* getWorld();
	Player* getPlayer();
	Player* getPlayer2();
	Ball* getBall();
	Graph* getGraph();

	void begin();

	void setTime(int minutes);
	void setGoals(int goals);
	void setMap(int id);

	int getTeamAGoals();
	int getTeamBGoals();

	int getTimeRemaining() const;

	int getElapsedTime() const;

	void teamAScored();

	void teamBScored();

	void teamAWin();

	void teamBWin();

	bool hasWinner() const;

	void ballPossessionCheat(bool teamA);

	void changeTimeRemaining(int seconds);

	std::chrono::system_clock::time_point getTimeLimit();

	void endGame();

	int getGoalLimit();


	bool gameOver;
	bool isOvertime;
	int ballPossessionTeamA;
	int ballPossessionTeamB;
	std::chrono::system_clock::time_point gameEnded;

private:
	//Settings
	int gameTime; //Default 180(seconden)
	int maxGoals;
	float gravity;
	char* map;
	std::chrono::system_clock::time_point beginTime;
	std::chrono::system_clock::time_point timeLimit;


	int firstGoalTime;

	int goalsTeamA;
	int goalsTeamB;

	Graph *graph;
	World *world;
	Player *player;
	Player *player2;
	Ball *ball;
	
	const float WORLD_GRAVITY = 9.81f;
};

