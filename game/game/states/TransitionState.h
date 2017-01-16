#pragma once

#include "../../engine/core/State.h"
#include "../../engine/input/OnClickListener.h"
#include "../../engine/widgets/Button.h"
#include "GameSelectionState.h"

class TransitionState : public State, public OnClickListener
{
public:
	TransitionState(StateContext* context, Game* game);
	~TransitionState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;
	bool onClick(Widget* button) final;
private:
	Sprite* background;
	Game* previousGame;
};

