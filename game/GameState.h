#pragma once

#include "State.h"

class GameState : public State {
public:
	void OnStart() final;
	void OnRender() final;
	void OnUpdate() final;
	void OnExit() final;
};