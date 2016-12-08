#pragma once
#include "../../engine/core-entities/TextualEntity.h"
#include "../../engine/world/Body.h"

class Score : public TextualEntity
{
public:
	Score(int x = 590, int y = 10, int width = 100, int height = 50, Color color = Color("white"));
	virtual ~Score();
	const char* getText() override;
	Color getColor() override;
	int getX() override;
	int getY() override;
	int getWidth() override;
	int getHeight() override;
};

