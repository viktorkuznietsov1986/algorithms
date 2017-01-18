#include "EdgeWeightedGraph.h"



EdgeWeightedGraph::EdgeWeightedGraph(int V) : _v(V), _e(0) {
	_adj.resize(V);
}

EdgeWeightedGraph::~EdgeWeightedGraph() noexcept {

}

int EdgeWeightedGraph::V() const noexcept {
	return _v;
}

int EdgeWeightedGraph::E() const noexcept {
	return _e;
}

void EdgeWeightedGraph::addEdge(const Edge& e) {
	int v = e.either();
	int w = e.other(v);

	_adj[v].push_front(e);
	_adj[w].push_front(e);
	++_e;
}

std::list<Edge> EdgeWeightedGraph::edges() const {
	std::list<Edge> result;

	for (int v = 0; v < _v; ++v) {
		for (std::list<Edge>::const_iterator it = _adj[v].begin(); it != _adj[v].end(); ++it) {
			if (it->other(v) > v)
				result.push_back(*it);
		}
	}

	return result;
}
