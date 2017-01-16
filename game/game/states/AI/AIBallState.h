#pragma once
#include "D:\game\game\engine\core\State.h"
#include "../../../engine/location/Graph.h"
#include "../../Game.h"


class AIBallState :
	public State
{
public:
	AIBallState(StateContext*, Game*);
	~AIBallState();

	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	Game* game;
};

