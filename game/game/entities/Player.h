#pragma once

#include "../../engine/world/Body.h"
#include "../../engine/core-entities/DrawableEntity.h"
#include <chrono>

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
	bool isInRangeOf(Body* b) const;
	void hitByEnemy(Ball* b) const;
	float getY() const override;

	int ballpossession;
private:
	PlayerState state;
};