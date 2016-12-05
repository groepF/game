#pragma once
#include "../../../engine/core-entities/TextualEntity.h"

class Score : public TextualEntity
{
public:
	Score(int x = 590, int y = 10, int width = 100, int height = 50, Color color = Color("white"));
	~Score();
	std::string GetText() override;
};

