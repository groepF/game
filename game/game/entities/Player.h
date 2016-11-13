#pragma once

#include "../../engine/world/Body.h"

enum PlayerState
{
	PLAYER_LEFT,
	PLAYER_RIGHT,
	PLAYER_STOP
};

class Player : public Body {
public:
	Player(float x, float y);

	void move() const;
	void jump();
	void setPlayerState(PlayerState state);

private:
	PlayerState state;
};