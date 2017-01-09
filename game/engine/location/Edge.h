#pragma once

#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex* source, Vertex* target, int weight = 1);
	~Edge();

	Vertex* getSource() const;
	Vertex* getTarget() const;
	Vertex* getDestination(Vertex* from) const;

	bool isEdge(Vertex* source, Vertex* target) const;

	int getWeight() const;
	int getGuessWeight() const;

private:
	Vertex *source, *target;
	int weight;
};

