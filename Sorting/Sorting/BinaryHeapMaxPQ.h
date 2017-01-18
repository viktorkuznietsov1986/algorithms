#pragma once

#include <cassert>
#include <memory>
#include "PriorityQueue.h"

const size_t ARRAY_LENGTH = 10;

template <typename T>
class BinaryHeapMaxPQ :
	public CPriorityQueue<T>
{
public:


	BinaryHeapMaxPQ() : CPriorityQueue<T>(ARRAY_LENGTH) {

	}
	
	~BinaryHeapMaxPQ() {

	}

	virtual std::shared_ptr<T> max() const {
		assert(size() != 0);
		return std::shared_ptr<T>(new T(pq[1]));
	}

	virtual std::shared_ptr<T> delMax() {
		assert(size() != 0);

		std::shared_ptr<T> result = max();
		
		exch(1, N);
		--N;
		sink(1);
		pq.pop_back();

		if (pq.capacity() < N / 2) {
			pq.resize(N / 2);
		}

		return result;
	}

	virtual void insert(T v) {
		
		if (pq.capacity() < N + 1) {
			pq.resize(N * 2);
		}

		pq.push_back(v);
		swim(++N);

	}
};

