#pragma once
#include <string>

class LevelUnlocker
{
public:
	void unlockLevel1();
	void unlockLevel2();
	void unlockLevel3();
	bool getLevelUnlocked(int level);
private:
	std::string getBoolString(bool value);
};

