#pragma once
#include "EdgeWeightedGraph.h"
#include "UnionFind.h"
#include "..\Sorting\IndexMinPQ.h"
#include "Edge.h"

#include <memory>
#include <list>

class PrimsMST
{
public:
	PrimsMST(EdgeWeightedGraph& g);
	~PrimsMST();

	/*std::list<Edge>::iterator edgesBegin() noexcept { return mst.begin(); }
	std::list<Edge>::iterator edgesEnd() noexcept { return mst.end(); }

	std::list<Edge>::const_iterator edgesCBegin() const noexcept { return mst.cbegin(); }
	std::list<Edge>::const_iterator edgesCEnd() const noexcept { return mst.cend(); }*/

	double weight() const { return _weight; }

	std::list<Edge> edges() const;

protected:
	void visit(EdgeWeightedGraph& g, int v);

private:
	std::vector<Edge> edgeTo;
	std::vector<double> distTo;
	std::vector<bool> marked;
	std::unique_ptr<IndexMinPQ<double>> pq;

	double _weight;
};

