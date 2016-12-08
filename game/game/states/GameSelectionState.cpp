#include "GameSelectionState.h"
#include "GameState.h"


GameSelectionState::GameSelectionState(StateContext* context) :
	State(context)
{
}


GameSelectionState::~GameSelectionState()
{
}

void GameSelectionState::onCreate()
{
	Log::debug("OnCreate GameSelectionState");

	game = new Game();
}

void GameSelectionState::onRender(Screen* screen)
{
}

void GameSelectionState::onUpdate(Keyboard* keyboard)
{
	context->setState(new GameState(context, game));
}

void GameSelectionState::onDestroy()
{
	Log::debug("OnDestroy GameSelectionState");
}
