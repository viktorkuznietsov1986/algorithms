#include "EdgeWeightedDigraphDense.h"
#include "DenseGraphHasEdgeException.h"

#include <cassert>



EdgeWeightedDigraphDense::EdgeWeightedDigraphDense(int V) : _v(V), _e(0) {
	_adj.resize(V);

	for (int i = 0; i < V; ++i) {
		_adj[i].resize(V);

		for (int v = 0; v < V; ++v) {
			_adj[i][v] = 0.0;
		}
	}
}


EdgeWeightedDigraphDense::~EdgeWeightedDigraphDense() {
}

void EdgeWeightedDigraphDense::addEdge(int from, int to, double weight) {
	assert(from >= 0 && from < _v);
	assert(to >= 0 && to < _v);

	if (hasEdge(from, to)) {
		throw DenseGraphHasEdgeException(from, to);
	}
	else {
		_adj[from][to] = weight;
		++_e;
	}
}

std::list<DirectedEdge> EdgeWeightedDigraphDense::adj(int v) const {
	std::list<DirectedEdge> result;

	for (int w = 0; w < _v; ++w) {
		if (hasEdge(v, w))
			result.push_back(DirectedEdge(v, w, _adj[v][w]));
	}

	return result;
}

std::list<DirectedEdge> EdgeWeightedDigraphDense::edges() const {
	std::list<DirectedEdge> result;

	for (int v = 0; v < _v; ++v) {
		auto adjList = adj(v);
		for (std::list<DirectedEdge>::const_iterator edge = adjList.begin(); edge != adjList.end(); ++edge) {
			result.push_back(*edge);
		}
	}

	return result;
}

EdgeWeightedDigraphDense EdgeWeightedDigraphDense::reverse() const {
	// todo implement
	return EdgeWeightedDigraphDense(_v);
}

std::ostream& operator<<(std::ostream& os, const EdgeWeightedDigraphDense& g) {
	// todo
	return os;
}
