#include "LevelReader.h"
#include <sstream>
#include <iterator>


LevelReader::LevelReader(const char* filename)
{
	tmx_parser.load(filename);
	this->width = tmx_parser.mapInfo.width;
	this->height = tmx_parser.mapInfo.height;
}


LevelReader::~LevelReader()
{
}

int LevelReader::getLevelWidth()
{
	return this->width;
}

int LevelReader::getLevelHeight()
{
	return this->height;
}

/**
* Gets Tiles from data tilelayer
* @return A vector filled with GID's from the datalayer
*/
std::vector<int> LevelReader::getTiles()
{

	for (std::map<std::string, TMX::Parser::TileLayer>::iterator it = tmx_parser.tileLayer.begin(); it != tmx_parser.tileLayer.end(); ++it) {
		
		//Make string readable
		std::istringstream readable_data(tmx_parser.tileLayer[it->first].data.contents);

		//Create new vector for tiles
		std::vector<int> tiles;

		std::string temp;

		while(std::getline(readable_data, temp, ','))
		{
			//Add tiles to array
			tiles.push_back(std::stoi(temp));
		}

		return tiles;
	}
}

/**
* Gets TileSet 
* @return A vector filled with sprites of every tile for the game
*/
std::vector<std::shared_ptr<Sprite>> LevelReader::getTileSet()
{
	std::vector<std::shared_ptr<Sprite>> tileSet;

	for(auto item : tmx_parser.tilesetList)
	{
		//Start reading the tiles from left to right, row to row
		for (int row = 0; row < item.tilecount / item.columns; row++)
		{
			for (int col = 0; col < item.columns; col++)
			{
				//Calculates the x and y position in the sprite
				int x = row * item.tileheight;
				int y = col * item.tilewidth;
				//Create new tile to return
				std::shared_ptr<Sprite> tile = std::make_shared<Sprite>(Sprite(item.name, y, x, item.tilewidth, item.tileheight));
				tileSet.push_back(tile);
			}
		}
	}

	return tileSet;
}

std::vector<int> LevelReader::getPlayerLocation()
{
	std::vector<int> playerLoc;

	for(auto item : tmx_parser.objectGroup)
	{
		if(item.first == "spawn")
		{
			for(auto it : item.second.object)
			{
				if(it.first == "player")
				{
					playerLoc.push_back(it.second.x);
					playerLoc.push_back(it.second.y);
				}
			}
		}
	}

	return playerLoc;
}

std::vector<int> LevelReader::getBallLocation()
{
	std::vector<int> ballLoc;

	return ballLoc;
}

std::vector<int> LevelReader::getEnemyLocation()
{
	std::vector<int> enemyLoc;

	return enemyLoc;
}



