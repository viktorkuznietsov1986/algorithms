#pragma once
#include <iostream>

class DirectedEdge
{
public:
	DirectedEdge(int v, int w, double wght) : _from(v), _to(w), _weight(wght) {}
	~DirectedEdge() {}

	double weight() const { return _weight; }

	int from() const { return _from; }
	int to() const { return _to; }

	friend std::ostream& operator<<(std::ostream& os, const DirectedEdge& e) {
		os << e._from << "->" << e._to << " " << e._weight;
		return os;
	}

private:
	int _from;
	int _to;
	double _weight;
};

