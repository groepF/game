#pragma once

#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../entities/Player.h"
#include "../../engine/Entities/FpsCounter.h"
#include "../../engine/core/StateContext.h"
#include "../entities/Ball.h"
#include "../entities/Enemy.h"

class GameState : public State {
public:
	GameState(StateContext* context);
	~GameState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	World *world;
	Player *player;
	Enemy *ai;
	Ball *ball;
	std::unique_ptr<FpsCounter> fpsCounter;
	bool showingFPS;
	const float WORLD_GRAVITY = 9.81f;
};
