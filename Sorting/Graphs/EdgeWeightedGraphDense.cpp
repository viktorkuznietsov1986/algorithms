#include "EdgeWeightedGraphDense.h"
#include <cassert>



EdgeWeightedGraphDense::EdgeWeightedGraphDense(int v) : _v(v), _e(0)
{
	adjacencyMatrix.resize(v);

	for (int i = 0; i < v; ++i) {
		adjacencyMatrix[i].resize(v);

		for (int j = 0; j < v; ++j)
			adjacencyMatrix[i][j] = INFINITY;
	}


}


EdgeWeightedGraphDense::~EdgeWeightedGraphDense()
{
}

void EdgeWeightedGraphDense::addEdge(int v, int w, double weight) {
	assert(v >= 0 && v < _v);
	assert(w >= 0 && w < _v);
	assert(v != w);
	
	if (adjacencyMatrix[v][w] == INFINITY) {
		adjacencyMatrix[v][w] = weight;
		adjacencyMatrix[w][v] = weight;
		++_e;
	}
	else {
		// todo: parallel edges are not allowed
	}
}

std::list<Edge> EdgeWeightedGraphDense::adj(int v) const {
	assert(v >= 0 && v < _v);
	
	std::list<Edge> result;

	for (int w = 0; w < _v; ++w) {
		auto weight = adjacencyMatrix[v][w];

		if (weight == INFINITY)
			continue;

		result.push_back(Edge(v, w, weight));
	}

	return result;
}

std::list<Edge> EdgeWeightedGraphDense::edges() const {
	std::list<Edge> result;

	for (int v = 0; v < _v; ++v) {
		for (int w = v; w < _v; ++w) {
			auto weight = adjacencyMatrix[v][w];

			if (weight == INFINITY)
				continue;

			result.push_back(Edge(v, w, weight));
		}
	}

	return result;
}
