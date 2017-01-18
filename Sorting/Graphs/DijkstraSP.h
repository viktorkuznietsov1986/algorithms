#pragma once
#include "IShortestPaths.h"
#include "EdgeWeightedDigraph.h"
#include "..\Sorting\IndexMinPQ.h"

#include <vector>
#include <cassert>


class DijkstraSP :
	public IShortestPaths
{
public:
	DijkstraSP(const EdgeWeightedDigraph& g, int s);
	~DijkstraSP();

	virtual double distTo(int v) const { assert(v >= 0 && v < _distTo.size()); return _distTo[v]; }
	virtual bool hasPathTo(int v) const { assert(v >= 0 && v < _distTo.size()); return _distTo[v] != INFINITY; }
	virtual std::list<DirectedEdge*> pathTo(int v) const = 0;

private:
	void relax(const EdgeWeightedDigraph& g, int v);

private:
	std::vector<double> _distTo;
	std::vector<DirectedEdge*> _edgeTo;
	IndexMinPQ<double> _pq;
};

