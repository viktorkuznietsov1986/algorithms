#include "Topological.h"

Topological::Topological(const EdgeWeightedDigraph& g) {
	_marked.resize(g.V());

	for (int v = 0; v < g.V(); ++v) {
		_marked[v] = false;
	}

	for (int v = 0; v < g.V(); ++v) {
		if (!_marked[v])
			dfs(g, v);
	}
}

// todo need to make sure it has no cycles

Topological::~Topological() {
}

void Topological::dfs(const EdgeWeightedDigraph& g, int v) {
	_marked[v] = true;

	for (DirectedEdge& e : g.adj(v)) {
		auto w = e.to();
		if (!_marked[w])
			dfs(g, w);
	}

	_order.push_front(v);
}
