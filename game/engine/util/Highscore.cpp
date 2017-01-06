#include "Highscore.h"
#include <fstream>
#include <iostream>
#include <string>

int Highscore::mostGoalsInOneMatch = 0;
int Highscore::scoreDifference = 0;
int Highscore::mostBallposession = 0;
int Highscore::longestGame = 0;
int Highscore::fastestGoal = 0;
int Highscore::fastestWin = 0;

std::vector<std::string> Highscore::load()
{
	std::vector<std::string> labels;

	std::string line;
	std::ifstream highscores(FILENAME);
	if (highscores.is_open())
	{
		while (getline(highscores, line))
		{
			labels.push_back(line);
		}
		highscores.close();
	}
	else {
		std::cout << "Unable to open file";
	}

	return labels;
}

void Highscore::save()
{
	std::ofstream highscores(FILENAME, std::fstream::out);
	if (highscores.is_open())
	{
		highscores << "Most goals in one match:" + std::to_string(Highscore::getMostGoalsInOneMatch()) + "\n";
		highscores << "Win with most score difference:" + std::to_string(Highscore::getScoreDifference()) + "\n";
		highscores << "Most ball posession ever:" + std::to_string(Highscore::getMostBallPosession()) + "%\n";
		highscores << "Longest game:" + std::to_string(Highscore::getLongestGame()) + " seconds\n";
		highscores << "Fastest goal:" + std::to_string(Highscore::getFastestGoal()) + " seconds\n";
		highscores << "Fastest win:" + std::to_string(Highscore::getFastestWin()) + " seconds\n";
		highscores.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void Highscore::setMostGoalsInOneMatch(int value)
{
	if (value > Highscore::mostGoalsInOneMatch)
	{
		Highscore::mostGoalsInOneMatch = value;
	}
}

void Highscore::setScoreDifference(int value)
{
	if (value > Highscore::scoreDifference)
	{
		Highscore::scoreDifference = value;
	}
}

void Highscore::setMostBallposession(int value)
{
	if (value > Highscore::mostBallposession)
	{
		Highscore::mostBallposession = value;
	}
}

void Highscore::setLongestGame(int value)
{
	if (value > Highscore::longestGame)
	{
		Highscore::longestGame = value;
	}
}

void Highscore::setFastestGoal(int value)
{
	if (value > Highscore::fastestGoal)
	{
		Highscore::fastestGoal = value;
	}
}

void Highscore::setFastestWin(int value)
{
	if (value > Highscore::fastestWin)
	{
		Highscore::fastestWin = value;
	}
}

int Highscore::getMostGoalsInOneMatch()
{
	return Highscore::mostGoalsInOneMatch;
}

int Highscore::getScoreDifference()
{
	return Highscore::scoreDifference;
}

int Highscore::getMostBallPosession()
{
	return Highscore::mostBallposession;
}

int Highscore::getLongestGame()
{
	return Highscore::longestGame;
}

int Highscore::getFastestGoal()
{
	return Highscore::fastestGoal;
}

int Highscore::getFastestWin()
{
	return Highscore::fastestWin;
}