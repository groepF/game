#include "AIBallState.h"


AIBallState::AIBallState(StateContext* context, Game* game) : State(context)
{
	this->game = game;
}


AIBallState::~AIBallState()
{
}

void AIBallState::onCreate()
{
}

void AIBallState::onRender(Screen* screen)
{
}

void AIBallState::onUpdate(Keyboard* keyboard)
{
	
	auto player2 = (Enemy*) game->getPlayer2();
	player2->subtractActionDelay();

	auto ball = game->getBall();
	auto graph = game->getGraph();

	auto distance = INT_MAX;
	Vertex* from = nullptr;
	for(auto vertex : graph->getVertices())
	{
		auto x = abs(player2->getX()*player2->getPPM() - vertex->getX());
		auto y = abs(player2->getY()*player2->getPPM() - vertex->getY());
		if(distance > x+y)
		{
			distance = (x + y);
			from = vertex;
		}
	}

	distance = INT_MAX;
	Vertex* to = nullptr;
	for (auto vertex : graph->getVertices())
	{
		auto x = abs(ball->getX()*ball->getPPM() - vertex->getX());
		auto y = abs(ball->getY()*ball->getPPM() - vertex->getY());
		if (distance > x + y)
		{
			distance = (x + y);
			to = vertex;
		}
	}

	auto path = graph->getPath(from, to);

	if (path.size() > 1)
	{

		auto next = path.getPath()[1];

		if (next->getX() > player2->getX()*player2->getPPM())
			player2->setPlayerState(PLAYER_RIGHT);
		else if (next->getX() < player2->getX()*player2->getPPM())
			player2->setPlayerState(PLAYER_LEFT);

		if (next->getY() < player2->getY()*player2->getPPM())
			player2->jump();

		if (player2->isInRangeOf(ball) && ball->isHeldBy(game->getPlayer()))
		{
			if(player2->canDoAction())
			{
				game->getPlayer()->hitByEnemy(ball, game->getPlayer());
				player2->doAction();
				player2->doPickup();
				game->getPlayer()->doPickup();
			}
				
		}
		else if (player2->isInRangeOf(ball))
		{
			ball->pickUp(player2);
		}
			

	}
	

}

void AIBallState::onDestroy()
{
}
