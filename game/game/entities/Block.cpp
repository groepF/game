#include "Block.h"

Block::Block(float x, float y, GrassType type)
{
	this->x = x;
	this->y = y;
	if (type == LEFT)
	{
		this->sprite = new Sprite("spritesheet", 0, 0, 70, 70);

	}
	else if (type == RIGHT)
	{
		this->sprite = new Sprite("spritesheet", 140, 0, 70, 70);
	}
	else
	{
		this->sprite = new Sprite("spritesheet", 70, 0, 70, 70);
	}
}

Block::~Block()
{ }

void Block::onUpdate(float delta)
{
}
