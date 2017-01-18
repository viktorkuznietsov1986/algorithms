#include "DirectedDFS.h"



DirectedDFS::DirectedDFS(const Digraph& g, int s) {
	_marked.resize(g.V());

	for (size_t i = 0; i < g.V(); ++i)
		_marked[i] = false;

	dfs(g, s);
}


DirectedDFS::~DirectedDFS() {
}

void DirectedDFS::dfs(const Digraph& g, int v) {
	_marked[v] = true;

	auto adj = g.adj(v);

	for (std::list<int>::const_iterator w = adj.begin(); w != adj.end(); ++w) {
		if (!_marked[*w])
			dfs(g, *w);
	}
}
