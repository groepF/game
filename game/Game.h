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

	char* getMap() const;
	World* getWorld() const;
	Player* getPlayer() const;
	Player* getPlayer2() const;
	Ball* getBall() const;

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
	float getSize() const;

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

	World *world;
	Player *player;
	Player *player2;
	Ball *ball;
	
	const float WORLD_GRAVITY = 9.81f;
};

