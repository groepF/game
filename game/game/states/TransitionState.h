#pragma once

#include "../../engine/core/State.h"
#include "../../engine/input/OnClickListener.h"

#include "../../engine/widgets/Button.h"
#include "../../engine/util/Log.h"
#include "MenuState.h"
#include "GameState.h"
#include "GameSelectionState.h"

class TransitionState : public State, public OnClickListener
{
public:
	TransitionState(StateContext* context);
	~TransitionState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;
	bool onClick(Button* button) final;
private:
	Sprite* background;
};

