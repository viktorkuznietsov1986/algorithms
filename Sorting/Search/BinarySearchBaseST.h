#pragma once
#include "IIndexedSymbolTable.h"

template <typename Key, typename Value>
class BinarySearchBaseST : public IIndexedSymbolTable<Key, Value>
{
public:
	BinarySearchBaseST() {
		N = 0;
		cachedLocation = -1;
	}

	~BinarySearchBaseST() {

	}

	virtual void put(Key key, Value val) {
		if (!isEmpty()) {
			int i = cache(rank(key));

			if (i < N) {
				if (getKey(i) == key) {
					getValue(i) = val;
				}
				else {
					if (key > getKey(i)) {
						++i;
					}

					if (underlyingArraySize() == size()) {
						resize(2 * size());
					}

					for (int j = N; j > i; --j) {

						getKey(j) = getKey(j - 1);
						getValue(j) = getValue(j - 1);
					}

					getKey(i) = key;
					getValue(i) = val;
				}
			}
		}
		else {
			getKey(0) = key;
			getValue(0) = val;
		}

		++N;

	}

	virtual std::shared_ptr<Value> get(Key key) {
		if (!isEmpty()) {
			if (isKeyCached(key)) {
				return std::shared_ptr<Value>(new Value(getValue(cachedLocation)));
			}
			else {
				int i = cache(rank(key));

				if (i < N && getKey(i) == key) {
					return std::shared_ptr<Value>(new Value(getValue(i)));
				}
			}
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {
		if (!isEmpty()) {
			int i = rank(key);

			if (i < N && getKey(i) == key) {
				for (size_t j = i + 1; j < size(); ++j) {
					getKey(j - 1) = getKey(j);
					getValue(j - 1) = getValue(j);
				}

				--N;
			}
		}
	}

	virtual bool contains(Key key) const {
		if (!isEmpty()) {
			if (isKeyCached(key)) {
				return true;
			}
			else {
				int i = rank(key);

				if (i < N && getKey(i) == key) {
					return true;
				}
			}
		}

		return false;

	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual size_t size() const {
		return N;
	}

	virtual int rank(Key key) const {
		size_t lo = 0;
		size_t hi = N - 1;

		while (lo < hi) {
			size_t mid = lo + (hi - lo) / 2;
			if (getKey(mid) == key) {
				return mid;
			}
			else if (key < getKey(mid))
				hi = mid - 1;
			else
				lo = mid + 1;
		}

		return lo;
	}

	virtual Key min() const {
		return getKey(0);
	}

	virtual Key max() const {
		return getKey(N - 1);
	}

	virtual Key ceiling(Key key) const {
		int i = rank(key);
		return select(i);
	}

	virtual Key floor(Key key) const {
		int i = rank(key);
		return select(i - 1);
	}

	virtual int size(Key lo, Key hi) const {
		if (hi < lo)
			return 0;

		int rlo = rank(lo);
		int rhi = rank(hi);

		if (contains(hi)) {
			return rhi - rlo + 1;
		}

		return rhi - rlo;
	}

	virtual Key select(int k) const {
		return getKey(k);
	}

	virtual void deleteMin() {
		Delete(min());
	}

	virtual void deleteMax() {
		Delete(max());
	}

protected:
	bool isKeyCached(Key key) const {
		return cachedLocation > -1 && cachedLocation < size() && getKey(cachedLocation) == key;
	}

	int cache(int loc) {
		cachedLocation = loc;
		return loc;
	}

protected:
	virtual Key& getKey(size_t i) = 0;
	virtual Key getKey(size_t i) const = 0;
	virtual Value& getValue(size_t i) = 0;
	virtual size_t underlyingArraySize() const = 0;
	virtual void resize(size_t capacity) = 0;

protected:
	size_t N;
	int cachedLocation;
};

