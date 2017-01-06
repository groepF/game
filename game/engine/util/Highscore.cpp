#include "Highscore.h"
#include <fstream>
#include <iostream>
#include <string>

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
		highscores << "Most goals in one match:" + std::to_string(mostGoalsInOneMatch) + "\n";
		highscores << "Win with most score difference:" + std::to_string(scoreDifference) + "\n";
		highscores << "Most ball posession ever:" + std::to_string(mostBallposession) + "%\n";
		highscores << "Longest game:" + std::to_string(longestGame) + " seconds\n";
		highscores << "Fastest goal:" + std::to_string(fastestGoal) + " seconds\n";
		highscores << "Fastest win:" + std::to_string(fastestWin) + " seconds\n";
		highscores.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void Highscore::setMostGoalsInOneMatch(int value)
{
	if (value > mostGoalsInOneMatch)
	{
		mostGoalsInOneMatch = value;
	}
}

void Highscore::setScoreDifference(int value)
{
	if (value > scoreDifference)
	{
		scoreDifference = value;
	}
}

void Highscore::setMostBallposession(int value)
{
	if (value > mostBallposession)
	{
		mostBallposession = value;
	}
}

void Highscore::setLongestGame(int value)
{
	if (value > longestGame)
	{
		longestGame = value;
	}
}

void Highscore::setFastestGoal(int value)
{
	if (value > fastestGoal)
	{
		fastestGoal = value;
	}
}

void Highscore::setFastestWin(int value)
{
	if (value > fastestWin)
	{
		fastestWin = value;
	}
}

int Highscore::getMostGoalsInOneMatch()
{
	return mostGoalsInOneMatch;
}

int Highscore::getScoreDifference()
{
	return scoreDifference;
}

int Highscore::getMostBallPosession()
{
	return mostBallposession;
}

int Highscore::getLongestGame()
{
	return longestGame;
}

int Highscore::getFastestGoal()
{
	return fastestGoal;
}

int Highscore::getFastestWin()
{
	return fastestWin;
}