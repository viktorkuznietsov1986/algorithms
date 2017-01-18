#include "Digraph.h"



Digraph::Digraph(int V) : _v(V), _e(0) {
	edges.resize(V);
}


Digraph::~Digraph() {
}


void Digraph::addEdge(int v, int w) {
	edges[v].push_front(w);
	++_e;
}

Digraph& Digraph::reverse() const {
	Digraph result(_v);

	for (size_t v = 0; v < _v; ++v) {
		auto adjustmentList = adj(v);

		for (std::list<int>::const_iterator w = adjustmentList.begin(); w != adjustmentList.end(); ++w) {
			result.addEdge(*w, v);
		}
	}

	return result;
}
