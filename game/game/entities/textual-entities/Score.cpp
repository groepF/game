#include "Score.h"



Score::Score(int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color)
{
}


Score::~Score()
{
}

std::string Score::GetText()
{
	return "0 - 0"; //todo Replace with actual score.
}
