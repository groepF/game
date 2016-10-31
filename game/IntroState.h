#pragma once

#include "State.h"

class IntroState : public State {
public:
	void OnStart() final;
	void OnRender() final;
	void OnUpdate() final;
	void OnExit() final;
};