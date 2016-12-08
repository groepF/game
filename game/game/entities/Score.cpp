#include "Score.h"


Score::Score(int x, int y, int width, int height, Color color) : TextualEntity("score", x, y, width, height, color)
{
}


Score::~Score()
{
}


const char* Score::getText()
{
	return "0 - 0"; // todo change to actual score.
}

Color Score::getColor()
{
	return color;
}

int Score::getX()
{
	return x;
}

int Score::getY()
{
	return y;
}

int Score::getWidth()
{
	return width;
}

int Score::getHeight()
{
	return height;
}
