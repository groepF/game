#include "Timer.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"
#include "../../Game.h"


Timer::Timer(Game* game, int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color), game(game){}

std::string Timer::getText()
{
	return std::to_string(this->game->getTimeRemaining());
}

Color Timer::getColor()
{
	return color;
}

void Timer::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}
