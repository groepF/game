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

	void onClick(Button* button) final;

private:
	Sprite* background;
	Sprite* logo;
};

