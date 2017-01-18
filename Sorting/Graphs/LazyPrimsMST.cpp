#include "LazyPrimsMST.h"



LazyPrimsMST::LazyPrimsMST(EdgeWeightedGraph& g) {
	marked.resize(g.V());
	_weight = 0.0;

	visit(g, 0);
	

	while (pq.size()) {
		auto e = pq.top();
		pq.pop();
		auto v = e.either();
		auto w = e.other(v);

		if (marked[v] && marked[w])
			continue;

		if (!marked[v])
			visit(g, v);

		if (!marked[w])
			visit(g, w);

		_weight += e.weight();
		mst.push_back(e);
	}
}


LazyPrimsMST::~LazyPrimsMST() {

}

void LazyPrimsMST::visit(EdgeWeightedGraph& g, int v) {

	marked[v] = true;
	
	for (std::list<Edge>::const_iterator e = g.adjCBegin(v); e != g.adjEnd(v); ++e) {
		if (!marked[e->other(v)])
			pq.push(*e);
	}
}
