#pragma once

#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../entities/Player.h"
#include "../../engine/core-entities/FpsCounter.h"
#include "../../engine/core/StateContext.h"
#include "../entities/Ball.h"
#include "../entities/Enemy.h"
#include "../../Game.h"
#include "../entities/Enemy.h"

class GameState : public State {
public:
	GameState(StateContext* context, Game* game);
	~GameState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	Game *game;
	World *world;
	Player *player;
	Player *player2;
	Ball *ball;
	FpsCounter* fpsCounter;
	const float WORLD_GRAVITY = 9.81f;
	bool isDebug;
	bool showGrid;
	bool showHybricGrid;
};
