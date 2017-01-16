#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include "../../game/entities/Ball.h"
#include "../../game/Game.h"

class ContactListener : public b2ContactListener
{
private:
	Game* game;

public:
	ContactListener(Game* game);

	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
};
