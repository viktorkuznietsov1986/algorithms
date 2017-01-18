#include "PrimsMST.h"



PrimsMST::PrimsMST(EdgeWeightedGraph& g) {
	pq = std::make_unique<IndexMinPQ<double>>();

	edgeTo.resize(g.V());
	for (int i = 0; i < g.V(); ++i) {
		distTo[i] = INFINITY;
	}

	distTo.resize(g.V());

	pq->insert(0, 0.0);
	distTo[0] = 0.0;

	while (pq->size()) {
		visit(g, pq->delMin());
	}
}

PrimsMST::~PrimsMST() {

}

void PrimsMST::visit(EdgeWeightedGraph& g, int v) {
	
	marked[v] = true;
	

	for (std::list<Edge>::iterator edge = g.adjBegin(v); edge != g.adjEnd(v); ++edge) {
		auto w = edge->other(v);

		if (marked[w])
			continue;

		if (edge->weight() < distTo[w]) {
			edgeTo[w] = *edge;
			distTo[w] = edge->weight();
			
			if (pq->contains(w)) {
				pq->changeKey(w, edge->weight());
			}
			else {
				pq->insert(w, edge->weight());
			}
			
		}
	}

}

std::list<Edge> PrimsMST::edges() const {
	std::list<Edge> result;

	for (std::vector<Edge>::const_iterator e = edgeTo.begin(); e != edgeTo.end(); ++e) {
		auto v = e->either();
		auto w = e->other(v);

		if (v == w)
			continue;

		result.push_back(*e);
	}

	return result;
}
