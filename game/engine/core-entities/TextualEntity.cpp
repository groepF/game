#include "TextualEntity.h"
#include "../graphics/render-strategies/RenderTextStrategy.h"
#include "../util/Log.h"

TextualEntity::TextualEntity(std::string identifier, int x, int y, int width, int height, Color color, std::string text): Body(x, y, width, height)
{
	this->identifier = identifier;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->text = text;
}

void TextualEntity::Render(Screen& screen, bool debug) const
{
	if(renderStrategy == nullptr)
	{
		Log::error("Your textual entity does not have a renderStrategy. Please set it. (You'll most likely want to use the RenderTextStrategy)");
		return;
	}
	renderStrategy->Render(screen);
}

std::string TextualEntity::get_identifier() const
{
	return this->identifier;
}

std::string TextualEntity::getText()
{
	return text;
}

Color TextualEntity::getColor()
{
	return Color("white");
}

int TextualEntity::getX()
{
	return x;
}

int TextualEntity::getY()
{
	return y;
}

int TextualEntity::getWidth()
{
	return width;
}

int TextualEntity::getHeight()
{
	return height;
}

void TextualEntity::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}
