#pragma once
#include "Widget.h"
#include <SDL/SDL.h>
#include "../graphics/Screen.h"
#include "../input/OnClickListener.h"

class Button : public Widget
{
public:
	Button(std::string id, int x, int y, int width, int height, std::string text, OnClickListener* listener);
	~Button();
	
	void onCreate() final;
	void onRender(Screen *screen) final;
	bool onUpdate(Keyboard *keyboard, Mouse *mouse) final;
	void onDestroy() final;

	bool inBounds(int posX, int posY) const;

	std::string getText() const;
	void select();
	void deselect();
private:
	bool selected;
	bool hovering, pressing;
	int x, y, width, height;
	std::string text;
	Sprite *hovered, *normal, *pressed;
	OnClickListener *listener;
};

