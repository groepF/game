#include "Highscore.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Config.h"

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
			if (line.size() < 1)
			{
				continue;
			}
			labels.push_back(line);
			auto value = String::split(String::split(line, ':').at(1), ' ').at(0);
			parseValue(String::split(line, ':').at(0), std::stoi(value));
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
		highscores << "Most ball posession ever:" + std::to_string(Highscore::getMostBallPosession()) + " %\n";
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
	if (value < Highscore::fastestGoal || Highscore::fastestGoal == 0)
	{
		Highscore::fastestGoal = value;
	}
}

void Highscore::setFastestWin(int value)
{
	if (value < Highscore::fastestWin || Highscore::fastestWin == 0)
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

void Highscore::parseValue(const std::string name, const int value)
{
	if (name == "Most goals in one match")
	{
		Highscore::mostGoalsInOneMatch = value;
	} 
	else if (name == "Win with most score difference")
	{
		Highscore::scoreDifference = value;
	}
	else if (name == "Most ball posession ever")
	{
		Highscore::mostBallposession = value;
	}
	else if (name == "Longest game")
	{
		Highscore::longestGame = value;
	}
	else if (name == "Fastest goal")
	{
		Highscore::fastestGoal = value;
	}
	else if (name == "Fastest win")
	{
		Highscore::fastestWin = value;
	}
}
