#pragma once

#include <vector>
#include <list>

class Digraph
{
public:
	Digraph(int V);
	~Digraph();

	void addEdge(int v, int w);
	std::list<int> adj(int v) const { return edges[v]; }
	std::list<int> adj(int v) { return edges[v]; }

	size_t V() const { return _v; }
	size_t E() const { return _e; }

	Digraph& reverse() const;

private:
	std::vector<std::list<int>> edges;
	size_t _v;
	size_t _e;
};

