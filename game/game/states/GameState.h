#pragma once

#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../entities/Player.h"
#include "../../engine/Entities/FpsCounter.h"

class GameState : public State {
public:
	GameState(StateContext* context);
	void onCreate(Event *event) final;
	void onRender(Screen *screen) final;
	void onUpdate(Event *event) final;
	void onDestroy() final;

private:
	World *world;
	Player *player;
	FpsCounter* fpsCounter;
};
