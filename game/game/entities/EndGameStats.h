#pragma once
#include "../../engine/core-entities/TextualEntity.h"
#include "../../Game.h"

class EndGameStats : public TextualEntity
{
public:
	EndGameStats(Game* game, int x = 590, int y = 90, int width = 100, int height = 500, Color color = Color("black"));

	~EndGameStats();
	virtual std::string getText() override;

private:
	Game* game;
};
