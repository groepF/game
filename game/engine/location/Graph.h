#pragma once
#include <vector>
#include "Vertex.h"
#include <vector>
#include "Edge.h"
#include <map>
#include <queue>
#include <functional>
#include "Path.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addVertex(Vertex* vertex);
	void addEdge(Edge* edge);

	std::vector<Vertex*> getVertices() const;
	std::vector<Edge*> getEdges() const;

	Path getPath(Vertex* source, Vertex* target);
	std::vector<Edge*> getEdges(Vertex* source);

private:
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
};

