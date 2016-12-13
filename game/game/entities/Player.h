#pragma once

#include "../../engine/world/Body.h"
#include "../../engine/core-entities/DrawableEntity.h"

class Ball;
class Enemy;

enum PlayerState
{
	PLAYER_LEFT,
	PLAYER_RIGHT,
	PLAYER_STOP
};

class Player : public DrawableEntity {
public:
	Player(float x, float y);

	void move() const;
	void jump();
	void setPlayerState(PlayerState state);
	PlayerState getPlayerState() const;
	bool canPickup(Body* b) const;
	void hitByEnemy(Ball* b) const;

private:
	PlayerState state;
};