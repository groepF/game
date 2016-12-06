#pragma once

#include "../../engine/world/Body.h"

class Enemy;

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
	PlayerState getPlayerState() const;
	bool canPickup(Body* b) const;
	void hitByEnemy(Enemy* e) const;

private:
	PlayerState state;
};