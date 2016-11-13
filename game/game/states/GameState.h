#pragma once

#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../entities/Block.h"
#include "../entities/Player.h"
#include <Box2D/Dynamics/b2World.h>
#include "../../engine/world/Body.h"
#include "../../engine/world/Ball.h"

class GameState : public State {
public:
	void onCreate(Event *event) final;
	void onRender(Screen *screen) final;
	void onUpdate(Event *event) final;
	void onDestroy() final;

private:
	b2World *world;
	Body* body;
	Ball* ball;
};
