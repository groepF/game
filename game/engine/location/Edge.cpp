#include "Edge.h"

Edge::Edge(Vertex* source, Vertex* target, int weight) : source(source), target(target), weight(weight)
{
}

Edge::~Edge()
{
}

Vertex* Edge::getSource() const
{
	return source;
}

Vertex* Edge::getTarget() const
{
	return target;
}

Vertex* Edge::getDestination(Vertex* from) const
{
	if (from == source)
	{
		return target;
	}
	return source;
}

bool Edge::isEdge(Vertex* source, Vertex* target) const
{
	return getSource() == source && getTarget() == target || getTarget() == source && getSource() == target;
}

int Edge::getWeight() const
{
	return weight;
}

int Edge::getGuessWeight() const
{
	return weight * source->getDistanceTo(target);
}