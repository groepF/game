#include "Score.h"
#include "../../engine/graphics/render-strategies/RenderTextStrategy.h"


Score::Score(int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color)
{
	auto dataProvider = std::make_shared<Score>(*this);
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(dataProvider));
}

std::string Score::getText()
{
	return "0 - 0"; // todo change to actual score.
}

Color Score::getColor()
{
	return color;
}

