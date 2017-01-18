#include "DenseGraphHasEdgeException.h"

DenseGraphHasEdgeException::DenseGraphHasEdgeException(int from, int to) {
	_msg = "Dense graph already has the edge leading from " + std::to_string(from) + " to " + std::to_string(to) + ".";
}

DenseGraphHasEdgeException::~DenseGraphHasEdgeException() {
}

const char* DenseGraphHasEdgeException::what() const {
	return _msg.c_str();
}


