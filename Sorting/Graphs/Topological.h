#pragma once
#include "EdgeWeightedDigraph.h"

#include <list>
#include <vector>

class Topological
{
public:
	Topological(const EdgeWeightedDigraph& g);
	~Topological();

	std::list<int> order() const {
		return _order;
	}

private:
	void dfs(const EdgeWeightedDigraph& g, int v);

private:
	std::list<int> _order;
	std::vector<bool> _marked;
};

