#include "Game.h"
#include "../engine/util/Highscore.h"
#include "../GraphRepository.h"
#include "entities/Player.h"


Game::Game()
{
	this->world = new World(WORLD_GRAVITY);

	//Default map
	this->map = "./res/maps/level1.tmx";
	this->size = 0.2f;

	auto size = 0.2f;

	player = new Player((size * 2) * 3, (size * 2) * 1, false);
	player2 = new Player((size * 2) * 61, (size * 2) * 1, false);
	ball = new Ball((size * 2) * 32, (size * 2) * 1);

	//Default settings
	this->gameTime = 3;
	this->maxGoals = 5;

	this->isOvertime = false;
	isOvertime = false;
	gameOver = false;
}


Game::~Game()
{
	delete world;
}

char* Game::getMap() const
{
	return this->map;
}

World* Game::getWorld() const
{
	return this->world;
}

Player* Game::getPlayer() const
{
	return this->player;
}


Player* Game::getPlayer2() const

{
	return this->player2;
}

Ball* Game::getBall() const
{
	return this->ball;
}

Graph* Game::getGraph()
{
	GraphRepository graphRepository;
	return graphRepository.getGraph(this->map);
}

void Game::setAI(bool ai)
{

	if(ai)
		player2 = new Enemy((size * 2) * 61, (size * 2) * 1, ai);		

}

void Game::begin()
{
	playing = true;
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

void Game::setWorld(World* world)
{
	this->world = world;
}

int Game::getTeamAGoals()
{
	return goalsTeamA;
}

int Game::getTeamBGoals()
{
	return goalsTeamB;
}

int Game::getTimeRemaining() const
{
	return std::chrono::duration_cast<std::chrono::seconds>(timeLimit - std::chrono::system_clock::now()).count();
}

int Game::getElapsedTime() const
{
	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - beginTime).count();
}

void Game::teamAScored()
{
	if (goalsTeamA == 0 && goalsTeamB == 0)
	{
		firstGoalTime = getElapsedTime();
	}
	goalsTeamA++;
}

void Game::teamBScored()
{
	if (goalsTeamA == 0 && goalsTeamB == 0)
	{
		firstGoalTime = getElapsedTime();
	}
	goalsTeamB++;
}

void Game::teamAWin()
{
	goalsTeamA = 10;
	goalsTeamB = 1;
	timeLimit = std::chrono::system_clock::now();
}

void Game::teamBWin()
{
	goalsTeamA = 1;
	goalsTeamB = 10;
	timeLimit = std::chrono::system_clock::now();
}

bool Game::hasWinner() const
{
	return goalsTeamA - goalsTeamB != 0;
}

void Game::ballPossessionCheat(bool teamA)
{
	if (teamA)
	{
		ballPossessionTeamA = 1;
		ballPossessionTeamB = 0;
		// makes it 100% for team A
	}
	else
	{
		ballPossessionTeamA = 0;
		ballPossessionTeamB = 1;
		// makes it 100% for team B
	}
}

void Game::changeTimeRemaining(int seconds)
{
	timeLimit += std::chrono::duration<int>(seconds);
}

std::chrono::system_clock::time_point Game::getTimeLimit()
{
	return timeLimit;
}

void Game::pauseGame()
{
	startPause = std::chrono::system_clock::now();
	//build pause screen
}

void Game::restartGame()
{
	//calculate the paused time by the current time and the time when the pause started
	std::chrono::system_clock::time_point restartTime = std::chrono::system_clock::now();
	auto timeDifference = std::chrono::duration_cast<std::chrono::milliseconds>(restartTime - startPause);
	//add the difference to beginTime and timeLimit 
	beginTime += timeDifference;
	timeLimit += timeDifference;

	//'close' pause screen
}

void Game::endGame()
{
	// save statistics and highscores, just always call the methods in highscore class
	// highscore class will only save the value if it is better

	// only save ball possession of player A, since this is our player

	Highscore::load(); // restore last highscore

	Highscore::setMostBallposession(player->ballpossession);
	Highscore::setMostGoalsInOneMatch(goalsTeamA + goalsTeamB);
	Highscore::setScoreDifference(abs(goalsTeamA - goalsTeamB));
	Highscore::setLongestGame(getElapsedTime());
	if (goalsTeamA > goalsTeamB)
	{
		Highscore::setFastestWin(getElapsedTime());
		Highscore::setFastestGoal(firstGoalTime);
	}

	Highscore::save();

	gameOver = true;
	gameEnded = std::chrono::system_clock::now();
}

int Game::getGoalLimit()
{
	return maxGoals;
}

void Game::calculateBallPossession()
{

	if (ball->isHeldBy(player2))
	{
		ballPossessionTeamB++;
	}
	if (ball->isHeldBy(player))
	{
		ballPossessionTeamA++;
	}

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
	player->ballpossession = ballPossession;
	if (ballPossessionTeamB > 0)
	{
		player2->ballpossession = 100 - ballPossession;
	}
	else
	{
		player2->ballpossession = 0;
	}

}

float Game::getSize() const
{
	return size;
}

int Game::getBallPossession(HoldingPlayer targetPlayer) const
{
	if (targetPlayer == NONE) { return 0; }
	if (getElapsedTime() <= 0) { return 0; }

	int possession = 0;
	if (targetPlayer == PLAYER1)
	{
		possession = player->ballpossession;
	}
	if (targetPlayer == PLAYER2)
	{
		possession = player2->ballpossession;
	}
	return possession;
}
