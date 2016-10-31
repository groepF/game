#include "StateManager.h"

void StateManager::Add(std::string identifier, State* state)
{
	if (_currentState == nullptr)
	{
		_currentState = state;
	}
	_states[identifier] = state;
}

void StateManager::TransitionTo(std::string identifier)
{
	if (_currentState != nullptr)
	{
		_currentState->OnExit();
	}
	_currentState = _states[identifier];
	_currentState->OnStart();
}

State* StateManager::GetCurrentState() const
{
	return _currentState;
}
