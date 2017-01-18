#pragma once
#include <cassert>
#include <memory>
#include "PriorityQueue.h"

const size_t ARRAY_LENGTH = 10;

template <typename T>
class BinaryHeapMinPQ :
	public CPriorityQueue<T>
{
public:
	BinaryHeapMinPQ() : CPriorityQueue<T>(ARRAY_LENGTH) {

	}

	virtual ~BinaryHeapMinPQ() {

	}

	virtual std::shared_ptr<T> min() const {
		assert(size() != 0);
		return std::shared_ptr<T>(new T(pq[1]));
	}

	virtual std::shared_ptr<T> delMin() {
		assert(size() != 0);

		std::shared_ptr<T> result = min();

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

protected:
	virtual bool less(int i, int j) const {
		assert(i >= N || j >= N);
		return pq[i] > pq[j];
	}
};

