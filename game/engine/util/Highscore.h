#pragma once
#include <vector>

#define FILENAME "highscores.txt"

class Highscore
{
public:
	static std::vector<std::string> load();
	static void save();
};