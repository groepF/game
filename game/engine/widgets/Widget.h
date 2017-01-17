#pragma once

#include "../input/Keyboard.h"
#include "../graphics/Screen.h"
#include "../input/Mouse.h"

class Widget
{
public:

	Widget();

	virtual ~Widget() {}
	Widget(Widget const &) = delete;
	Widget & operator=(Widget const &) = delete;

	virtual void onCreate() = 0;
	virtual void onRender(Screen *screen) = 0;
	virtual bool onUpdate(Keyboard *keyboard, Mouse* mouse) = 0;
	virtual void onDestroy() = 0;

	std::string getId() const;
	void setId(std::string id);
private:
	std::string id;
};

