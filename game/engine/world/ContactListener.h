#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include "../../game/entities/Ball.h"

class Game;

class ContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;

	void setGame(Game* game);

private:
	Game* game;
};
