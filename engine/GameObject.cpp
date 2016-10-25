#include "GameObject.h"



GameObject::GameObject()
{
	_body = new b2BodyDef();
}


GameObject::~GameObject()
{
	delete _body;
}

void GameObject::SetPosition(int x, int y) const
{
	_body->position.Set(x / 32, y / 32);
}

b2BodyDef* GameObject::Def() const
{
	return _body;
}
