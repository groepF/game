#include "Path.h"


Path::Path(): distance(0)
{
}

Path::Path(std::vector<Vertex*> path, int distance) : path(path), distance(distance)
{
}

Path::~Path()
{
}

void Path::setPath(std::vector<Vertex*> path)
{
	this->path = path;
}

void Path::setDistance(int distance)
{
	this->distance = distance;
}

std::vector<Vertex*> Path::getPath() const
{
	return path;
}

int Path::getDistance() const
{
	return distance;
}

int Path::size() const
{
	return path.size();
}

Vertex* Path::end()
{
	if (path.size() == 0) return nullptr;
	return path[path.size() - 1];
}
