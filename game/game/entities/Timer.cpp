#include "Timer.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"
#include "../../Game.h"


Timer::Timer(Game* game, int x, int y, int width, int height, Color color, Color colorOvertime) : TextualEntity("score", x, y, width, height, color),
game(game),
colorOvertime(colorOvertime) {}

std::string Timer::getText()
{
	if (game->isOvertime)
	{
		return "Overtime";
	}
	return std::to_string(this->game->getTimeRemaining()) + " seconds";
}

Color Timer::getColor()
{
	if(game->isOvertime)
	{
		return colorOvertime;
	}
	return color;
}

void Timer::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}
