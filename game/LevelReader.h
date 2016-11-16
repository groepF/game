#pragma once
#include "engine/world/parser/TMXParser.h"

class LevelReader
{
public:
	TMX::Parser tmx_parser;
	LevelReader(const char* filename);
	~LevelReader();

	int getLevelWidth();
	int getLevelHeight();
	std::vector<int> getTiles();
private:
	int width;
	int height;
};

