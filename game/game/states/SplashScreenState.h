#pragma once

#include "../../engine/core/State.h"
#include "../../engine/graphics/Sprite.h"
#include "GameState.h"

class SplashScreenState : public State {
public:
	SplashScreenState(StateContext* context);
	void onCreate(Event *event) final;
	void onRender(Screen *screen) final;
	void onUpdate(Event *event) final;
	void onDestroy() final;

private:
	int counter;
	bool hasReached;
	Sprite* sprite;
};