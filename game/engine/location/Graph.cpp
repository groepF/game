#include "Graph.h"


Graph::Graph()
{
}

Graph::~Graph()
{
	for (auto i = 0; i < vertices.size(); i++)
	{
		delete vertices[i];
	}
	vertices.clear();

	for (auto i = 0; i < edges.size(); i++)
	{
		delete edges[i];
	}

	edges.clear();
}

void Graph::addVertex(Vertex* vertex)
{
	vertices.push_back(vertex);
}

void Graph::addEdge(Edge* edge)
{
	edges.push_back(edge);
}

std::vector<Vertex*> Graph::getVertices() const
{
	return vertices;
}

std::vector<Edge*> Graph::getEdges() const
{
	return edges;
}

Path Graph::getPath(Vertex* source, Vertex* target)
{
	std::map<Vertex*, Vertex*> parents; // used for building the path (which node was connected with which node)
	std::map<Vertex*, int> distances; // map van room tot distance tot start

	typedef std::pair<int, Vertex*> pair; // cost, room

										  // set infinity at first run
	for (auto const& room : vertices)
	{
		distances[room] = INT_MAX;
	}

	std::priority_queue<pair, std::vector<pair>, std::greater<pair>> queue;

	queue.push(pair(0, source));

	distances[source] = 0;

	while (!queue.empty())
	{
		auto vertex = queue.top().second;
		auto cost = queue.top().first;
		queue.pop();

		// check if reached target
		if (vertex == target) break;

		// check if there is a shorter path
		if (distances[vertex] < cost) continue;

		for (const auto& edge : getEdges(vertex))
		{
			auto weight = edge->getGuessWeight() + 1; // edge weight
			auto edgeTarget = edge->getDestination(vertex);
			// check if there is a shorter path
			if (distances[vertex] + weight < distances[edgeTarget])
			{
				distances[edgeTarget] = distances[vertex] + weight;
				queue.push(pair(distances[edgeTarget], edgeTarget));
				parents[edgeTarget] = vertex;
			}
		}
	}

	// make path
	std::vector<Vertex*> path;
	for (auto v = target; v != source; v = parents[v])
		if (distances[v] != INT_MAX)
			path.push_back(v);

	path.push_back(source);

	// path is from end to start so reverse it
	std::reverse(path.begin(), path.end());

	int distance = distances[path[path.size() - 1]];

	return Path(path, distance);
}

std::vector<Edge*> Graph::getEdges(Vertex* source)
{
	std::vector<Edge*> vertexEdges;
	for (const auto& edge : edges)
	{
		if (edge->getSource() == source || edge->getTarget() == source)
		{
			vertexEdges.push_back(edge);
		}
	}
	return vertexEdges;
}