#pragma once

#include <list>
#include <vector>

#include "DirectedEdge.h"


class EdgeWeightedDigraphDense
{
public:
	EdgeWeightedDigraphDense(int V);
	virtual ~EdgeWeightedDigraphDense();

	int V() const { return _v; }
	int E() const { return _e; }

	void addEdge(int from, int to, double weight);

	std::list<DirectedEdge> adj(int v) const;
	std::list<DirectedEdge> edges() const;

	EdgeWeightedDigraphDense reverse() const;

	friend std::ostream& operator<<(std::ostream& os, const EdgeWeightedDigraphDense& g);

private:
	bool hasEdge(int from, int to) const { return _adj[from][to] != 0.0; }

private:
	std::vector<std::vector<double>> _adj;
	int _v;
	int _e;
};

