#pragma once

#include "../input/Keyboard.h"
#include "../graphics/Screen.h"

class StateContext;

class State
{
public:
	virtual ~State() {}
	State(State const &) = delete;
	State & operator=(State const &) = delete;

	virtual void onCreate() = 0;
	virtual void onRender(Screen *screen) = 0;
	virtual void onUpdate(Keyboard *keyboard) = 0;
	virtual void onDestroy() = 0;

protected:
	State(StateContext* context);
	StateContext* context;
};
