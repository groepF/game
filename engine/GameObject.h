#pragma once

#include "Box2D/Box2D.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void SetPosition(int x, int y) const;

	b2BodyDef* Def() const;

private:
	b2BodyDef* _body;
};

