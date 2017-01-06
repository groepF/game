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
		highscores << "This is a line.\n";
		highscores << "This is another line.\n";
		highscores.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}
