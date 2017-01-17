#include "Score.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"
#include "../Game.h"


Score::Score(Game* game, int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color), game(game) {}

std::string Score::getText()
{
	return std::to_string(this->game->getTeamAGoals()) + " - " + std::to_string(game->getTeamBGoals());
}

Color Score::getColor()
{
	return color;
}

void Score::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}
