#include "TextualEntity.h"

TextualEntity::TextualEntity(std::string identifier, int x, int y, int width, int height, Color color)
{
	this->identifier = identifier;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
}

void TextualEntity::Render(Screen& screen)
{
	screen.renderText(GetText(), color, x, y, width, height);
}

std::string TextualEntity::get_identifier() const
{
	return this->identifier;
}

