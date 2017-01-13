#pragma once
#include "engine/location/Graph.h"

class Graph;

class GraphRepository
{
public:
	GraphRepository();
	~GraphRepository();
	Graph* getGraph(char* map);
private:
	void generateGraph(Graph* graph, int map_id);
};

