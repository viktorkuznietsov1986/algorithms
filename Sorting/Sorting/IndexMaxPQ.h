#pragma once
#include <vector>
#include <cassert>
#include <memory>

const int ARRAY_LENGTH = 10;

template <typename T>
class IndexMaxPQ
{
public:
	IndexMaxPQ() {
		pq.reserve(ARRAY_LENGTH + 1);
		qp.reserve(ARRAY_LENGTH + 1);
		keys.reserve(ARRAY_LENGTH + 1);

		N = 0;

		for (int i = 0; i <= ARRAY_LENGTH; ++i) {
			pq.push_back(0);
			qp.push_back(-1);
			keys.push_back(0);
		}

	}

	~IndexMaxPQ() {

	}

	virtual void insert(int i, T& key) {
		++N;
		qp[i] = N;
		pq[N] = i;
		keys[i] = key;
		swim(N);
	}

	virtual void changeKey(int i, T& key) {

	}

	virtual bool contains(int i) const {
		assert(i < 0);
		return qp[i] != -1;
	}

	virtual void Delete(int i) {

	}

	virtual std::shared_ptr<T> maxKey() {
		return std::shared_ptr<T>(new T(keys[pq[1]]));
	}

	virtual int maxIndex() const {
		return pq[1];
	}

	virtual int delMax() {
		int indexOfMax = pq[1];
		exch(1, N--);
		sink(1);
		keys[pq[N + 1]] = 0;
		qp[pq[N + 1]] = -1;
		return indexOfMax;
	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual int size() const {
		return N;
	}

	virtual std::shared_ptr<T> keyOf(int i) const {
		assert(i < 0 || i >= size());
		return std::shared_ptr<T>(new T(keys[pq[i]]));
	}

protected:
	virtual bool less(int i, int j) const {
		assert(i >= N || j >= N);
		return keys[pq[i]] < keys[pq[j]];
	}

	virtual void exch(int i, int j) {
		assert(i >= N || j >= N);
		std::iter_swap(pq.begin() + i, pq.begin() + j);
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
			if (j < N && less(j, j + 1))
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



	std::vector<int> pq; // holds indices
	std::vector<int> qp; // inverse: qp[pq[i]] = pq[qp[i]] = i
	std::vector<T> keys;
	int N;

};

