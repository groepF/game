#pragma once
#include "../engine/world/World.h"
#include "entities/Player.h"
#include "entities/Ball.h"
#include "entities/Enemy.h"
#include "chrono"
#include "../engine/location/Graph.h"


class Game
{
public:
	Game();
	~Game();

	char* getMap() const;
	World* getWorld() const;
	Player* getPlayer() const;
	Player* getPlayer2() const;
	Ball* getBall() const;
	Graph* getGraph();

	void setAI(bool);

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

	void teamAWin();

	void teamBWin();

	bool hasWinner() const;

	void ballPossessionCheat(bool teamA);

	void changeTimeRemaining(int seconds);

	std::chrono::system_clock::time_point getTimeLimit();

	void pauseGame();
	void restartGame();

	void endGame();

	int getGoalLimit();
	void calculateBallPossession();

	bool gameOver;
	bool isOvertime;
	int ballPossessionTeamA;
	int ballPossessionTeamB;
	bool playing = false;
	float getSize() const;
	std::chrono::system_clock::time_point gameEnded;

	enum HoldingPlayer {PLAYER1,PLAYER2,NONE};
	int getBallPossession(HoldingPlayer targetPlayer) const;
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

	float size;
	Graph *graph;

	World *world;
	Player *player;
	Player *player2;
	Ball *ball;
	
	const float WORLD_GRAVITY = 9.81f;
};

