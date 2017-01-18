#include "EdgeWeightedDigraph.h"

#include <cassert>



EdgeWeightedDigraph::EdgeWeightedDigraph(int V) : _v(V), _e(0) {
	_edges.resize(_v);
}

EdgeWeightedDigraph::~EdgeWeightedDigraph() {
}

void EdgeWeightedDigraph::addEdge(int from, int to, double weight) {
	addEdge(DirectedEdge(from, to, weight));
}

void EdgeWeightedDigraph::addEdge(const DirectedEdge& e) {
	auto from = e.from();
	_edges[from].push_front(e);
	++_e;
}

std::list<DirectedEdge> EdgeWeightedDigraph::adj(int v) const {
	assert(v >= 0 && v < _v);

	return _edges[v];
}

std::list<DirectedEdge> EdgeWeightedDigraph::edges() const {
	std::list<DirectedEdge> result;

	for (size_t i = 0; i < _v; ++i) {
		for (std::list<DirectedEdge>::const_iterator edge = _edges[i].begin(); edge != _edges[i].end(); ++edge) {
			result.push_back(*edge);
		}
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const EdgeWeightedDigraph& g) {
	
	for (size_t i = 0; i < g._v; ++i) {
		os << i << ": ";
		
		for (std::list<DirectedEdge>::const_iterator edge = g._edges[i].begin(); edge != g._edges[i].end(); ++edge) {
			os << "(" << *edge << ") ";
		}

		os << std::endl;
	}

	return os;
}

EdgeWeightedDigraph EdgeWeightedDigraph::reverse() const {
	EdgeWeightedDigraph g(_v);

	for (int v = 0; v < _v; ++v) {
		for (DirectedEdge& e : adj(v)) {
			auto w = e.to();
			auto weight = e.weight();

			g.addEdge(DirectedEdge(w, v, weight));
		}
	}

	return g;
}
