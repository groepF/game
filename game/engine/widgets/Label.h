#pragma once
#include "Widget.h"

class Label : public Widget
{
public:
	Label(int x, int y, int width, int height, std::string text, Color color = Color{ "white" }, int gravity = 1);
	~Label();

	void onCreate() final;
	void onRender(Screen *screen) final;
	bool onUpdate(Keyboard *keyboard, Mouse *mouse) final;
	void onDestroy() final;

	std::string getText() const;
private:
	int x, y, width, height, gravity;
	Color color;
	std::string text;
};

