#pragma once
#include "ISet.h"

#include <vector>

template <typename Key>
class BinarySearchSET :
	public ISet<Key>
{
private:
	std::vector<Key> keys;
	size_t N;

public:
	BinarySearchSET() : BinarySearchSET(10) {

	}

	BinarySearchSET(size_t capacity) {
		N = 0;
		keys.resize(capacity);
	}

	virtual ~BinarySearchSET() {

	}

	virtual void add(Key key) {
		if (contains(key))
			return;

		addInternal(key);
	}

	virtual void Delete(Key key) {
		if (!contains(key))
			return;

		deleteInternal(key);
	}

	virtual bool contains(Key key) const {
		int i = rank(key);

		return (i >= 0) && keys[i] == key;
	}

	virtual size_t size() const {
		return N;
	}

protected:

	void deleteInternal(Key key) {
		int i = rank(key);

		for (size_t j = i+1; j < N; ++j) {
			keys[j-1] = keys[j];
		}

		--N;
	}

	void addInternal(Key key) {
		if (!isEmpty()) {

			int i = rank(key);
			
			if (i < N) {

				int j = N;

				if (key > keys[i]) {
					++i;
				}

				if (keys.size() == N)
					resize(2 * N);

				for (j; j > i; --j) {
					keys[j] = keys[j - 1];
				}

				keys[i] = key;
				++N;
			}
		}
		else {
			keys[0] = key;
			++N;
		}

		
	}

	void resize(size_t capacity) {
		if (capacity > 0)
			keys.resize(capacity);
	}

	int rank(Key key) {
		return rank(key, 0, N - 1);
	}

	int rank(Key key) const {
		return rank(key, 0, N - 1);
	}

	int rank(Key key, int lo, int hi) const {
		if (lo >= hi)
			return lo;

		int mid = lo + (hi - lo) / 2;

		if (key < keys[mid])
			return rank(key, lo, mid - 1);
		else if (key > keys[mid])
			return rank(key, mid + 1, hi);
		else 
			return mid;
	}
};

