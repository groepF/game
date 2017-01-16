#include "LevelUnlocker.h"
#include <fstream>
#include <iostream>
#include <string>
#include "engine/util/Config.h"

#define FILENAME "levels.txt"

void LevelUnlocker::unlockLevel1()
{
	bool level2Unlocked = getLevelUnlocked(2);
	bool level3Unlocked = getLevelUnlocked(3);

	std::ofstream levels(FILENAME, std::fstream::out);
	if (levels.is_open())
	{
		levels << "level1:true\n";
		levels << "level2:" + getBoolString(level2Unlocked) + "\n";
		levels << "level3:" + getBoolString(level3Unlocked);
		levels.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void LevelUnlocker::unlockLevel2()
{
	bool level1Unlocked = getLevelUnlocked(1);
	bool level3Unlocked = getLevelUnlocked(3);

	std::ofstream levels(FILENAME, std::fstream::out);
	if (levels.is_open())
	{
		levels << "level1:" + getBoolString(level1Unlocked) + "\n";
		levels << "level2:true\n";
		levels << "level3:" + getBoolString(level3Unlocked);
		levels.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void LevelUnlocker::unlockLevel3()
{
	bool level1Unlocked = getLevelUnlocked(1);
	bool level2Unlocked = getLevelUnlocked(2);

	std::ofstream levels(FILENAME, std::fstream::out);
	if (levels.is_open())
	{
		levels << "level1:" + getBoolString(level1Unlocked) + "\n";
		levels << "level2:" + getBoolString(level2Unlocked) + "\n";
		levels << "level3:true";
		levels.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

bool LevelUnlocker::getLevelUnlocked(int level)
{
	bool unlocked = false;

	std::string line;
	int linenumber = 1;
	std::ifstream levels(FILENAME);
	if (levels.is_open())
	{
		while (getline(levels, line))
		{
			if (line.size() < 1)
			{
				continue;
			}
			auto value = String::split(String::split(line, ':').at(1), ' ').at(0);
			if(linenumber == level && value == "true")
			{
				unlocked = true;
			}
			linenumber++;
		}
		levels.close();
	}
	else {
		std::cout << "Unable to open file";
	}

	return unlocked;
}

std::string LevelUnlocker::getBoolString(bool value)
{
	if(value)
	{
		return "true";
	} 
	
	return "false";
}