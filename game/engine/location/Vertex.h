#pragma once
#include <vector>
#include <cmath>

class Vertex
{
public:
	Vertex(const int x, const int y);
	~Vertex();

	int getX() const;
	int getY() const;

	int getDistanceTo(Vertex* other) const;
	int getDistanceTo(int otherX, int otherY) const;

private:
	const int x, y;
};

