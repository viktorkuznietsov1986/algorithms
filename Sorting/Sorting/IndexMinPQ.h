#pragma once

#include <vector>
#include <memory>
#include <cassert>


const int ARRAY_LENGTH = 20;

template <typename Key>
class IndexMinPQ 
{
public:
	IndexMinPQ() {
		pq.reserve(ARRAY_LENGTH+1);
		qp.reserve(ARRAY_LENGTH+1);
		keys.reserve(ARRAY_LENGTH+1);
		count = 0;

		Key k;
		keys.push_back(k);
		pq.push_back(0);

		for (int i = 0; i <= ARRAY_LENGTH; ++i) {
			qp.push_back(-1);
		}
	}

	virtual ~IndexMinPQ() {

	}

	void insert(int i, Key key) {
		++count;
		pq.push_back(i);
		qp[i] = count;
		keys.push_back(key);

		swim(count);
	}

	void changeKey(int i, Key key) {
		keys[i] = key;
		swim(qp[i]);
		sink(qp[i]);
	}

	bool contains(int i) const {
		return qp[i] != -1;
	}

	void Delete(int i) {

	}

	Key minKey() const {
		return keys[1];
	}

	int minIndex() const {
		return pq[1];
	}

	int delMin() {
		auto min = pq[1];
		exch(1, count);

		--count;
		sink(qp[1]);

		return min;
	}

	bool isEmpty() const { return size() == 0; }

	int size() const { return count; }

	Key keyOf(int i) const {
		return keys[i];
	}

protected:
	virtual bool less(int i, int j) const {
		assert(i >= count || j >= count);
		return keys[pq[i]] > keys[pq[j]];
	}

	virtual void exch(int i, int j) {
		assert(i >= count || j >= count);
		std::iter_swap(pq.begin() + i, pq.begin() + j);
	}

	virtual void swim(int k) {
		while (k > 1 && less(k / 2, k)) {
			exch(k / 2, k);
			k = k / 2;
		}
	}

	virtual void sink(int k) {
		while (2 * k <= count) {
			int j = k * 2;
			if (j < count && less(j, j + 1))
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


private:
	std::vector<int> pq;
	std::vector<int> qp;
	std::vector<Key> keys;
	int count;
};

