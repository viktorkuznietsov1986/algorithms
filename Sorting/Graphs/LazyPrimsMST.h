#pragma once
#include <list>
#include <iterator>
#include <vector>
#include <memory>
#include <queue>

#include "..\Sorting\BinaryHeapMinPQ.h"
#include "Edge.h"
#include "EdgeWeightedGraph.h"

class LazyPrimsMST
{
public:
	LazyPrimsMST(EdgeWeightedGraph& g);
	virtual ~LazyPrimsMST();

	std::list<Edge>::iterator edgesBegin() noexcept { return mst.begin(); }
	std::list<Edge>::iterator edgesEnd() noexcept { return mst.end(); }

	std::list<Edge>::const_iterator edgesCBegin() const noexcept { return mst.cbegin(); }
	std::list<Edge>::const_iterator edgesCEnd() const noexcept { return mst.cend(); }

	double weight() const { return _weight; }

protected:
	void visit(EdgeWeightedGraph& g, int v);

private:
	std::vector<bool> marked;
	std::list<Edge> mst;
	std::priority_queue<Edge> pq;
	double _weight;
};

