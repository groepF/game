#pragma once

#include "../core/Event.h"
#include "../graphics/Screen.h"

class StateContext;

class State
{
public:
	virtual ~State() {}
	State(State const &) = delete;
	State & operator=(State const &) = delete;

	virtual void onCreate(Event *event) = 0;
	virtual void onRender(Screen *screen) = 0;
	virtual void onUpdate(Event* event) = 0;
	virtual void onDestroy() = 0;

protected:
	State(StateContext* context);
	StateContext* context;
};
