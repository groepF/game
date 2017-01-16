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
	
	auto player2 = game->getPlayer2();
	auto ball = game->getBall();
	auto graph = game->getGraph();

	auto distance = INT_MAX;
	Vertex* from = nullptr;
	for(auto vertex : graph->getVertices())
	{
		auto x = abs(player2->getX() - vertex->getX());
		auto y = abs(player2->getY() - vertex->getY());
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
		auto x = abs(ball->getX() - vertex->getX());
		auto y = abs(ball->getY() - vertex->getY());
		if (distance > x + y)
		{
			distance = (x + y);
			to = vertex;
		}
	}

	auto path = graph->getPath(from, to);





}

void AIBallState::onDestroy()
{
}
