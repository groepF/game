#include "TextualEntity.h"

void TextualEntity::Render(Screen& screen)
{
	screen.renderText(GetText(), color, x, y, width, height);
}
