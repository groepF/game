#pragma once
#include "../util/Color.h"
#include "../graphics/Screen.h"

class TextualEntity
{
public:
	virtual ~TextualEntity() = default;

	void Render(Screen& screen);

protected:
	TextualEntity() = default;
	virtual const char* GetText() = 0;

	int x;
	int y;
	int width;
	int height;

	Color color;
};

