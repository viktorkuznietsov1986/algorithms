#include "AcyclicSP.h"
#include "Topological.h"

#include <memory>



AcyclicSP::AcyclicSP(const EdgeWeightedDigraph& g) {
	_distTo.resize(g.V());
	_edgeTo.resize(g.V());

	for (int v = 0; v < g.V(); ++v) {
		_distTo[v] = INFINITY;
		_edgeTo[v] = nullptr;
	}

	auto topological = std::make_unique<Topological>(g);

	for (int v : topological->order()) {
		relax(g, v);
	}
}


AcyclicSP::~AcyclicSP() {
}

void AcyclicSP::relax(const EdgeWeightedDigraph& g, int v) {
	for (DirectedEdge& e : g.adj(v)) {
		auto w = e.to();
		auto weight = e.weight();

		if (_distTo[w] > _distTo[v] + weight) {
			_distTo[w] = _distTo[v] + weight;
			_edgeTo[w] = &e;
		}
	}
}

std::list<DirectedEdge*> AcyclicSP::pathTo(int v) const {
	std::list<DirectedEdge*> result;

	if (hasPathTo(v)) {
		for (DirectedEdge* e = _edgeTo[v]; e != nullptr; e = _edgeTo[e->from()]) {
			result.push_front(e);
		}
	}

	return result;
}