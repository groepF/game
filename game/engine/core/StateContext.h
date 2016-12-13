#pragma once
#include "State.h"

class StateContext
{
public:
	StateContext();
	virtual ~StateContext();

	virtual void playMusic(std::string key) = 0;
	virtual void stopMusic() = 0;
	virtual void setState(State* state);
protected:
	State* currentState;
	virtual void stateUpdated() = 0;

};

