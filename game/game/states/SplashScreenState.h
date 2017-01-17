#pragma once

#include "../../engine/core/State.h"
#include "../../engine/graphics/Sprite.h"
#include "../../engine/core/StateContext.h"
#include "GameState.h"

class SplashScreenState : public State {
public:
	SplashScreenState(StateContext* context);
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	int counter;
	bool hasReached;
	Sprite* sprite;
};