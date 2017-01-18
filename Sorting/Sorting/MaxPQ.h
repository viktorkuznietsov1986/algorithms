#pragma once
#include "PriorityQueue.h"
template <typename T> class MaxPQ :
	public CPriorityQueue<T>
{
public:
	MaxPQ(int maxN) : CPriorityQueue(maxN) {

	}

	virtual void insert(T v) {

	}

	virtual T delMax() {
		return 0;
	}

protected:
	virtual void swim(int k) {

	}

	virtual void sink(int k) {

	}
};

