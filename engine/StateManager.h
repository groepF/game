#pragma once

#include "State.h"
#include <string>
#include <map>

class StateManager
{
public:
	static StateManager& GetInstance()
	{
		static StateManager _instance;

		return _instance;
	}
	StateManager(StateManager const&) = delete;
	void operator=(StateManager const&) = delete;

	void Add(std::string identifier, State* state);
	void TransitionTo(std::string identifier);

	State* GetCurrentState() const;

private:
	StateManager(): _currentState(nullptr)
	{
	}

	State* _currentState;
	std::map<std::string, State*> _states;
};
