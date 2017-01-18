#include "DijkstraSP.h"




DijkstraSP::DijkstraSP(const EdgeWeightedDigraph& g, int s) {
	_distTo.resize(g.V());
	for (std::vector<double>::iterator it = _distTo.begin(); it != _distTo.end(); ++it) {
		*it = INFINITY;
	}
	
	_edgeTo.resize(g.V());
	
	_distTo[s] = 0;
	
	_pq.insert(s, 0.0);

	while (_pq.size()) {
		auto v = _pq.delMin();
		relax(g, v);
	}
	

}

void DijkstraSP::relax(const EdgeWeightedDigraph& g, int v) {
	auto adj = g.adj(v);

	for (DirectedEdge& edge : adj) {
		int w = edge.to();
		double weight = edge.weight();

		if (_distTo[w] > _distTo[v] + weight) {
			_distTo[w] = _distTo[v] + weight;
			_edgeTo[w] = &edge;

			if (_pq.contains(w))
				_pq.changeKey(w, _distTo[w]);
			else
				_pq.insert(w, _distTo[w]);
		}
	}
}


DijkstraSP::~DijkstraSP(){
}

std::list<DirectedEdge*> DijkstraSP::pathTo(int v) const {
	std::list<DirectedEdge*> result;

	while (_distTo[v]) {
		auto e = _edgeTo[v];
		auto from = e->from();
		result.push_back(_edgeTo[v]);
		v = from;
	}

	return result;
}
