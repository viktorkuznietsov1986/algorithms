#pragma once
#include "IBasicOperations.h"
#include <vector>
#include <cassert>

template<typename T> class CPriorityQueue :
		public IBasicOperations
{
public:
	CPriorityQueue(int maxN) {
		pq.reserve(maxN+1);
		T t;
		pq.push_back(t);
		N = 0;
	}

	CPriorityQueue(const CPriorityQueue& priorityQueue) {
		pq(priorityQueue.pq);
		N = priorityQueue.N;
	}

	bool isEmpty() const {
		return N == 0;
	}

	virtual int size() const {
		return N;
	}

	virtual void insert(T v) = 0;
	

protected:
	virtual bool less(int i, int j) const {
		assert(i >= N || j >= N);
		return pq[i] < pq[j];
	}

	virtual void exch(int i, int j) {
		assert(i >= N || j >= N);
		std::iter_swap(pq.begin()+i, pq.begin()+j);
	}

	virtual void swim(int k) {
		while (k > 1 && less(k / 2, k)) {
			exch(k / 2, k);
			k = k / 2;
		}
	}

	virtual void sink(int k) {
		while (2 * k <= N) {
			int j = k * 2;
			if (j < N && less(j, j+1))
				++j;

			if (less(k, j)) {
				exch(k, j);
				k = j;
			}
			else {
				break;
			}
		}
	}



	std::vector<T>  pq;
	int N;

};

