#include "KruskalMST.h"
#include "..\Sorting\BinaryHeapMinPQ.h"
#include "UnionFind.h"

#include <memory>



KruskalMST::KruskalMST(const EdgeWeightedGraph& g)
{
	_weight = 0.0;

	auto pq = std::make_unique<BinaryHeapMinPQ<Edge>>();
	auto edges = g.edges();

	for (std::list<Edge>::const_iterator edge = edges.begin(); edge != edges.end(); ++edge)
		pq->insert(*edge);

	auto uf = std::make_unique<UnionFind>(g.V());

	while (pq->size()) {
		auto edge = pq->delMin();

		auto v = edge->either();
		auto w = edge->other(v);

		if (uf->connected(v,w))
			continue;

		uf->connect(v, w);

		_weight += edge->weight();
		mst.push_back(*edge);
	}
}


KruskalMST::~KruskalMST()
{
}
