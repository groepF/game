#pragma once
#include <vector>

#define FILENAME "highscores.txt"

class Highscore
{
public:
	static std::vector<std::string> load();
	static void save();

	static void setMostGoalsInOneMatch(int value);
	static void setScoreDifference(int value);
	static void setMostBallposession(int value);
	static void setLongestGame(int value);
	static void setFastestGoal(int value);
	static void setFastestWin(int value);

	static int getMostGoalsInOneMatch();
	static int getScoreDifference();
	static int getMostBallPosession();
	static int getLongestGame();
	static int getFastestGoal();
	static int getFastestWin();

private:
	static int mostGoalsInOneMatch, scoreDifference, mostBallposession, longestGame, fastestGoal, fastestWin;
};