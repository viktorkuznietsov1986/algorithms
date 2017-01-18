#pragma once
#include <vector>
#include <list>

#include "Edge.h"

class EdgeWeightedGraphDense
{
public:
	EdgeWeightedGraphDense(int v);
	virtual ~EdgeWeightedGraphDense();

	int V() const noexcept { return _v; }
	int E() const noexcept { return _e; }
	void addEdge(int v, int w, double weight);

	std::list<Edge> adj(int v) const;

	std::list<Edge> edges() const;

private:
	int _v;
	int _e;
	std::vector<std::vector<double>> adjacencyMatrix;
};

