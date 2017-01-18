#pragma once
#include "BinarySearchBaseST.h"
#include "MergeSort.h"
#include <vector>

const size_t MAX_ARRAY_SIZE = 10;

template <typename Key, typename Value>
class BinarySearchSingleItemST :
	public BinarySearchBaseST<Key, Value>
{
public:
	struct Item {
		Key key;
		Value value;
		Item(Key k, Value v) : key(k), value(v) {}
		Item() {}
		bool operator<(const Item& other) const {
			return key < other.key;
		}

		bool operator==(const Item& other) const {
			return key == other.key;
		}

		bool operator>(const Item& other) const {
			return key > other.key;
		}

		bool operator<=(const Item& other) const {
			return *this < other || *this == other;
		}

		bool operator>=(const Item& other) const {
			return *this > other || *this == other;
		}
	};

public:
	BinarySearchSingleItemST() {
		resize(MAX_ARRAY_SIZE);
		N = 0;
	}

	BinarySearchSingleItemST(const std::vector<Item>& a) {
		// copy array; do a merge sort
		N = a.size();
		items.resize(N);
		std::copy(a.begin(), a.end(), items.begin());
		CMergeSort<Item>::sort(items);
	}

	~BinarySearchSingleItemST() {

	}

	//virtual void put(Key key, Value val) {
	//	if (!isEmpty()) {
	//		int i = rank(key);

	//		if (i < N) {
	//			if (getKey(i) == key) {
	//				getValue(i) = val;
	//			}
	//			else {
	//				if (underlyingArraySize() == size()) {
	//					resize(2 * size());
	//				}

	//				for (int j = N; j > i; --j) {

	//					/*getKey(j) = getKey(j - 1);
	//					getValue(j) = getValue(j - 1);*/
	//					items[j] = items[j - 1];
	//				}

	//				items[i] = Item(key, val);
	//				/*getKey(i) = key;
	//				getValue(i) = val;*/
	//			}
	//		}
	//		else {
	//			items[i] = Item(key, val);
	//		}
	//	}
	//	else {
	//		getKey(0) = key;
	//		getValue(0) = val;
	//	}

	//	++N;

	//}

	/*virtual std::shared_ptr<Value> get(Key key) {
		if (!isEmpty()) {
			int i = rank(key);

			if (i < N && getKey(i) == key) {
				return std::shared_ptr<Value>(new Value(getValue(i)));
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
	}*/

	/*virtual bool contains(Key key) const {
		if (!isEmpty()) {
			int i = rank(key);

			if (i < N && getKey(i) == key) {
				return true;
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
		size_t hi = N-1;

		while (lo <= hi) {
			size_t mid = lo + (hi - lo) / 2;
			if (getKey(mid) == key)
				return mid;
			else if (getKey(mid) > key)
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
	}*/

protected:
	virtual Key& getKey(size_t i) {
		return items[i].key;
	}

	virtual Key getKey(size_t i) const {
		return items[i].key;
	}

	virtual Value& getValue(size_t i) {
		return items[i].value;
	}

	virtual size_t underlyingArraySize() const {
		return items.size();
	}

	virtual void resize(size_t capacity) {
		if (capacity > 0) {
			items.resize(capacity);
		}
	}

private:
	std::vector<Item> items;
};

