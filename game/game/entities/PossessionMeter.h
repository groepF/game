#pragma once
#include "../../engine/core-entities/TextualEntity.h"

class Game;

class PossessionMeter : public TextualEntity
{
public:
	enum Side { PLAYER1, PLAYER2 };
	PossessionMeter(std::string identifier, Side side, Game* game, int x = 590, int y = 590, int width = 100, int height = 50, Color color = Color("white"));
	~PossessionMeter();

	std::string getText() override;
	Color getColor() override;
	void setDefaultRenderStrategy() override;


private:
	Game* game;
	Side side;
};

