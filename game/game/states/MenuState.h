#pragma once
#include "../../engine/core/State.h"
#include "../../engine/input/OnClickListener.h"

class MenuState : public State, public OnClickListener
{
public:
	MenuState(StateContext* context);
	~MenuState();

	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

	bool onClick(Widget* button) final;

	void chooseRandomAd();

private:
	Sprite* background;
	Sprite* logo;
	Sprite* ad;
};

