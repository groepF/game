#pragma once

#include "../../engine/core/State.h"
#include "../../Game.h";
#include "../../engine/world/World.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"
#include "../entities/Enemy.h"

class GameSelectionState : public State
{
public:
	GameSelectionState(StateContext* context);
	~GameSelectionState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;
private:
	Game *game;
};

