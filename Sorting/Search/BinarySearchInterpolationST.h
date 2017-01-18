#pragma once
#include "BinarySearchST.h"
#include <cmath>

template <typename Key, typename Value>
class BinarySearchInterpolationST : public BinarySearchST<Key, Value>
{
public:
	BinarySearchInterpolationST() {

	}
	~BinarySearchInterpolationST() {

	}

	

protected:
	virtual int rank(Key key, int lo, int hi) const {
		if (lo >= hi) {
			return lo;
		}

		Key divider = (key - getKey(lo)) / (getKey(hi) - getKey(lo));


		if (divider <= 0) {
			return lo;
		}

		int mid = lo + (hi - lo) / divider;

		if (key < getKey(mid))
			return rank(key, lo, mid - 1);
		else if (key > getKey(mid))
			return rank(key, mid + 1, hi);
		else
			return mid;
	}
};

