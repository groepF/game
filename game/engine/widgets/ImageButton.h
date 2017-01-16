#pragma once
#include "Widget.h"
#include "../input/OnClickListener.h"

class ImageButton : public Widget
{
public:
	ImageButton(std::string id, std::string image, int x, int y, int width, int height, bool locked, OnClickListener* listener);
	~ImageButton();

	void onCreate() final;
	void onRender(Screen *screen) final;
	bool onUpdate(Keyboard *keyboard, Mouse *mouse) final;
	void onDestroy() final;

	void setLocked(bool locked);

	bool isLocked() const;

	bool inBounds(int posX, int posY) const;

	void select();
	void deselect();
private:
	std::string image;
	bool selected, locked;
	bool hovering, pressing;
	int x, y, width, height;

	Sprite *normal, *lock, *check;
	OnClickListener* listener;
};

