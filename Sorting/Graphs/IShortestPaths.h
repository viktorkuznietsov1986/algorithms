#pragma once

#include <list>

#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"

class IShortestPaths
{
public:
	virtual double distTo(int v) const = 0;
	virtual bool hasPathTo(int v) const = 0;
	virtual std::list<DirectedEdge*> pathTo(int v) const = 0;

protected:
	void relax(const EdgeWeightedDigraph& g, int v);
};

