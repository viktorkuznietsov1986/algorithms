#pragma once

#include <list>
#include <vector>

#include "DirectedEdge.h"

class EdgeWeightedDigraph
{
public:
	EdgeWeightedDigraph(int V);
	~EdgeWeightedDigraph();

	int V() const { return _v; }
	int E() const { return _e; }

	void addEdge(int from, int to, double weight);
	void addEdge(const DirectedEdge& e);

	std::list<DirectedEdge> adj(int v) const;
	std::list<DirectedEdge> edges() const;

	EdgeWeightedDigraph reverse() const;

	friend std::ostream& operator<<(std::ostream& os, const EdgeWeightedDigraph& g);

private:
	const int _v;
	int _e;
	std::vector<std::list<DirectedEdge>> _edges;
};

