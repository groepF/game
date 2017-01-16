#include "PossessionMeter.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"
#include "../Game.h"


PossessionMeter::PossessionMeter(std::string identifier, Side side, Game* game, int x, int y, int width, int height, Color color) : TextualEntity(identifier, x, y, width, height, color)
{
	this->game = game;
	this->side = side;
}

PossessionMeter::~PossessionMeter()
{
}

std::string PossessionMeter::getText()
{
	int possession = 0;

	switch(side)
	{
	case PLAYER1:
		possession = game->getBallPossession(Game::PLAYER1);
		break;
	case PLAYER2:
		possession = game->getBallPossession(Game::PLAYER2);
		break;
	default: break;
	}

	return std::to_string(possession) + "%";
}

Color PossessionMeter::getColor()
{
	return color;
}

void PossessionMeter::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}