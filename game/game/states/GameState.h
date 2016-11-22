#pragma once

#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../entities/Player.h"
#include "../../engine/Entities/FpsCounter.h"
#include "../../engine/core/StateContext.h"

class GameState : public State {
public:
	GameState(StateContext* context);
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	World *world;
	Player *player;
	FpsCounter* fpsCounter;
	const float WORLD_GRAVITY = 9.81f;
};
