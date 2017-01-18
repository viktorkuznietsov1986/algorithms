#pragma once

#include "Edge.h"
#include <vector>
#include <list>
#include <iterator>

class EdgeWeightedGraph
{
public:
	EdgeWeightedGraph(int V);
	~EdgeWeightedGraph() noexcept;

	int V() const noexcept;
	int E() const noexcept;
	void addEdge(const Edge& e);

	std::list<Edge>::iterator adjBegin(int v) { return _adj[v].begin(); }
	std::list<Edge>::iterator adjEnd(int v) { return _adj[v].end(); }

	std::list<Edge>::const_iterator adjCBegin(int v) { return _adj[v].cbegin(); }
	std::list<Edge>::const_iterator adjCEnd(int v) { return _adj[v].cend(); }

	std::list<Edge> edges() const;

private:
	int _v;
	int _e;
	std::vector<std::list<Edge>> _adj;
};

