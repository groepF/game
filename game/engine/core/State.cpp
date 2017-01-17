#include "State.h"

State::State(StateContext* context) : context(context)
{
}

void State::renderWidgets(Screen* screen, Mouse* mouse, Keyboard* keyboard)
{
	for (auto& widget : widgets)
	{
		if(!widget->onUpdate(keyboard, mouse))
		{
			break;
		}
		widget->onRender(screen);
	}
}

void State::addWidget(Widget* widget)
{
	widget->onCreate();
	widgets.push_back(widget);
}

void State::removeWidget(Widget* widget)
{
	widget->onDestroy();
	widgets.erase(std::remove(widgets.begin(), widgets.end(), widget), widgets.end());
	delete widget;
}
