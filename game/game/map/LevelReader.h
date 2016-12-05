#pragma once
#include "../../engine/world/parser/TMXParser.h"
#include "../../engine/graphics/Sprite.h"
#include <memory>

class LevelReader
{
public:
	TMX::Parser tmx_parser;
	LevelReader(const char* filename);
	~LevelReader();

	int getLevelWidth();
	int getLevelHeight();
	std::vector<int> getTiles();
	std::vector<std::shared_ptr<Sprite>> getTileSet();

	std::vector<int> getPlayerLocation();
	std::vector<int> getBallLocation();
	std::vector<int> getEnemyLocation();

private:
	int width;
	int height;
};

