#pragma once
#include "../../../engine/core/State.h"
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

	void setBallAsGoal(Graph*);
	void setGoalAsGoal(Graph*);

private:
	Game* game;
	Vertex* goal;
};

