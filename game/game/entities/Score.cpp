#include "Score.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"


Score::Score(int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color) {}

std::string Score::getText()
{
	return "0 - 0"; // todo change to actual score.
}

Color Score::getColor()
{
	return color;
}

void Score::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}
