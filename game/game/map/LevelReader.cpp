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



std::vector<int> LevelReader::getTiles()
{

	for (std::map<std::string, TMX::Parser::TileLayer>::iterator it = tmx_parser.tileLayer.begin(); it != tmx_parser.tileLayer.end(); ++it) {
		
		//Readable maken
		std::istringstream readable_data(tmx_parser.tileLayer[it->first].data.contents);

		//Maak de array met voor tiles
		std::vector<int> tiles;

		std::string temp;

		while(std::getline(readable_data, temp, ','))
		{
			//Voeg tile toe aan array
			tiles.push_back(std::stoi(temp));
		}

		return tiles;
	}
}



