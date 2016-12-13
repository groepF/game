#pragma once
#include "../../engine/core-entities/TextualEntity.h"
#include "../../engine/world/Body.h"

class Game;

class Score : public TextualEntity
{
public:
	Score(Game* game, int x = 590, int y = 10, int width = 100, int height = 50, Color color = Color("white"));
	virtual ~Score() {};
	std::string getText() override;
	Color getColor() override;
	void setDefaultRenderStrategy() override;

private: 
	Game* game;
};
