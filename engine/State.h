#pragma once

#include <SDL/SDL.h>

class State
{
public:
	virtual ~State() {}

	State(State const &) = delete;
	State & operator=(State const &) = delete;

	virtual void OnStart() = 0;
	virtual void OnRender() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnExit() = 0;

protected:
	State() = default;
};