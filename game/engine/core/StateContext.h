#pragma once
#include "State.h"

class StateContext
{
public:
	StateContext();
	virtual ~StateContext();

	virtual void setState(State* state);
protected:
	State* currentState;
	virtual void stateUpdated() = 0;
};

