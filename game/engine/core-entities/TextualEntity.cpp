#include "TextualEntity.h"
#include "../graphics/render-strategies/RenderTextStrategy.h"

TextualEntity::TextualEntity(std::string identifier, int x, int y, int width, int height, Color color): Body(x, y, width, height)
{
	this->identifier = identifier;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
	auto dataProvider = std::make_shared<ITextRenderDataPorvider>(*this);
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(dataProvider));
}

void TextualEntity::Render(Screen& screen) const
{
	renderStrategy->Render(screen);
}

std::string TextualEntity::get_identifier() const
{
	return this->identifier;
}

