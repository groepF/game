#include "StateContext.h"


StateContext::StateContext(): currentState(nullptr){}

StateContext::~StateContext()
{
	if (currentState != nullptr)
	{
		currentState->onDestroy();
		delete currentState;
		currentState = nullptr;
	}
}

void StateContext::setState(State* state)
{
	if (currentState != nullptr)
	{
		currentState->onDestroy();
	}
	delete currentState;

	currentState = state;
	stateUpdated();
}

std::vector<std::string> StateContext::getFilesIn(const std::string path) const
{
	return {};
}
