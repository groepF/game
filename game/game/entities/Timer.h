#pragma once
#include "../../engine/core-entities/TextualEntity.h"
#include "../../engine/world/Body.h"

class Game;

class Timer : public TextualEntity
{
public:
	Timer(Game* game, int x = 590, int y = 50, int width = 100, int height = 50, Color color = Color("white"), Color colorOvertime = Color("red"));
	virtual ~Timer() {};
	std::string getText() override;
	Color getColor() override;
	void setDefaultRenderStrategy() override;

private: 
	Game* game;
	Color colorOvertime;
};
