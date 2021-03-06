#include "EndGameStats.h"


EndGameStats::EndGameStats(Game* game, int x, int y, int width, int height, Color color) : TextualEntity("endGameScore", x, y, width, height, color)
{
	this->game = game;
}

EndGameStats::~EndGameStats()
{
}

std::string EndGameStats::getText()
{
	if (this->game->getTeamAGoals() > this->game->getTeamBGoals())
	{
		return " Player 1 wins!";
	}
	return " Player 2 wins!";

}
