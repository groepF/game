#include "Vertex.h"

Vertex::Vertex(const int x, const int y) : x(x), y(y)
{
}

Vertex::~Vertex()
{
}

int Vertex::getX() const
{
	return x;
}

int Vertex::getY() const
{
	return y;
}

int Vertex::getDistanceTo(Vertex* other) const
{
	auto x = other->getX() - getX();
	auto y = other->getY() - getY();
	return sqrt(x * x + y * y);
}

int Vertex::getDistanceTo(int otherX, int otherY) const
{
	auto x = otherX - getX();
	auto y = otherY - getY();
	return sqrt(x * x + y * y);
}
