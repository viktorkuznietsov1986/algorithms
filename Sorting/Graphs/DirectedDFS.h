#pragma once

#include "Digraph.h"

class DirectedDFS
{
public:
	DirectedDFS(const Digraph& g, int s);
	~DirectedDFS();

	bool hasRouteTo(int v) const { return _marked[v]; }

private:
	void dfs(const Digraph& g, int v);

private:
	std::vector<bool> _marked;
};

