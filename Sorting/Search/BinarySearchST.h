#pragma once
#include "BinarySearchBaseST.h"

#include <vector>

const size_t MAX_ARRAY_SIZE = 10;

template <typename Key, typename Value>
class BinarySearchST :
	public BinarySearchBaseST<Key, Value>
{
protected:
	using BinarySearchBaseST<Key, Value>::N;

public:
	BinarySearchST() {
		resize(MAX_ARRAY_SIZE);
	}
	~BinarySearchST() {

	}

	virtual int rank(Key key) const {
		return rank(key, 0, N - 1);
	}

protected:
	virtual Key& getKey(size_t i) {
		return keys[i];
	}

	virtual Key getKey(size_t i) const {
		return keys[i];
	}

	virtual Value& getValue(size_t i) {
		return values[i];
	}

	virtual size_t underlyingArraySize() const {
		return keys.size();
	}

	virtual void resize(size_t capacity) {
		if (capacity > 0) {
			keys.resize(capacity);
			values.resize(capacity);
		}
	}

	virtual int rank(Key key, int lo, int hi) const {
		if (lo >= hi) {
			return lo;
		}
		
		int mid = lo + (hi - lo) / 2;
		if (key < getKey(mid))
			return rank(key, lo, mid - 1);
		else if (key > getKey(mid))
			return rank(key, mid + 1, hi);
		else
			return mid;
	}

private:
	std::vector<Key> keys;
	std::vector<Value> values;
};

