#pragma once
#include "IShortestPaths.h"
#include "EdgeWeightedDigraph.h"

#include <cassert>

class AcyclicSP :
	public IShortestPaths
{
public:
	AcyclicSP(const EdgeWeightedDigraph& g);
	~AcyclicSP();

	virtual double distTo(int v) const { assert(v >= 0 && v < _distTo.size()); return _distTo[v]; }
	virtual bool hasPathTo(int v) const { assert(v >= 0 && v < _distTo.size()); return _distTo[v] != INFINITY; }
	virtual std::list<DirectedEdge*> pathTo(int v) const;

private:
	void relax(const EdgeWeightedDigraph& g, int v);

private:
	std::vector<double> _distTo;
	std::vector<DirectedEdge*> _edgeTo;
};

