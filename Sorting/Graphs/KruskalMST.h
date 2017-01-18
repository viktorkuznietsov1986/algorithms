#pragma once
#include <list>
#include <iterator>

#include "Edge.h"
#include "EdgeWeightedGraph.h"

class KruskalMST
{
public:
	KruskalMST(const EdgeWeightedGraph& g);
	~KruskalMST();

	std::list<Edge>::iterator edgesBegin() { return mst.begin(); }
	std::list<Edge>::iterator edgesEnd() { return mst.end(); }

	std::list<Edge>::const_iterator edgesCBegin() { return mst.cbegin(); }
	std::list<Edge>::const_iterator edgesCEnd() { return mst.cend(); }

	double weight() const { return _weight; }

private:
	std::list<Edge> mst;
	double _weight;
};

