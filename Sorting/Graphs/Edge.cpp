#include "Edge.h"
#include <exception>

Edge::Edge(int v, int w, double weight) : _v(v), _w(w), _weight(weight) {
}

Edge::~Edge() noexcept
{
}

int Edge::either() const noexcept {
	return _v;
}

int Edge::other(int v) const {
	if (v == _v) return _w;
	else if (v == _w) return _v;
	else {
		throw std::exception("Inconsistent edge.");
	}
	
}

bool Edge::operator<(const Edge& other) const {
	return _weight < other._weight;
}

bool Edge::operator>(const Edge& other) const {
	return _weight > other._weight;
}

bool Edge::operator==(const Edge& other) const {
	return _weight == other._weight;
}
