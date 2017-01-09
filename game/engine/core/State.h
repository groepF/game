#pragma once

#include "../input/Keyboard.h"
#include "../graphics/Screen.h"
#include "../widgets/Widget.h"
#include <vector>
#include <algorithm>

class Mouse;
class StateContext;

class State
{
public:
	virtual ~State()
	{
		for(auto &widget : widgets)
		{
			delete widget;
		}
		widgets.clear();
	}
	State(State const &) = delete;
	State & operator=(State const &) = delete;

	virtual void onCreate() = 0;
	virtual void onRender(Screen *screen) = 0;
	virtual void onUpdate(Keyboard *keyboard) = 0;
	virtual void onDestroy() = 0;

	void renderWidgets(Screen* screen, Mouse* mouse, Keyboard* keyboard);
	void addWidget(Widget* widget);
	void removeWidget(Widget* widget);

protected:
	State(StateContext* context);
	StateContext* context;
	std::vector<Widget*> widgets;
};
