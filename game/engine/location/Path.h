#pragma once
#include "Vertex.h"

class Path
{
public:
	Path();
	Path(std::vector<Vertex*> path, int distance);
	~Path();

	void setPath(std::vector<Vertex*> path);
	void setDistance(int distance);

	std::vector<Vertex*> getPath() const;

	int getDistance() const;
	int size() const;

	Vertex* end();

private:
	std::vector<Vertex*> path;
	int distance;
};

