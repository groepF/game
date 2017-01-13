#pragma once
#include "D:\game\game\engine\core\State.h"
class AIBallState :
	public State
{
public:
	AIBallState(StateContext*);
	~AIBallState();

	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;
};

