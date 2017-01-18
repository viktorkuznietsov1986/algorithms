#pragma once
#include "ISymbolTable.h"
#include <vector>

const size_t MAX_ARRAY_SIZE = 10;

template <typename Key, typename Value>
class ArrayST :
	public ISymbolTable<Key, Value>
{
private:
	struct Item {
		Key key;
		Value value;
		Item() {}
		Item(Key k, Value v) : key(k), value(v) {}
	};

	std::vector<Item> items;
	size_t N;

public:
	typedef typename std::vector<Item>::iterator iterator;
	typedef typename std::vector<Item>::const_iterator const_iterator;

	ArrayST() {
		resize(MAX_ARRAY_SIZE);
		N = 0;
	}

	virtual void put(Key key, Value val) {
		int i = rank(key);
		if (i > -1) {
			items[i].value = val;
		}
		else {
			if (size() == items.capacity()) {
				resize(size() * 2);
			}

			items[N] = Item(key, val);
			++N;
		}
	}

	virtual std::shared_ptr<Value> get(Key key) {
		int i = rank(key);

		if (i > -1) {
			if (i != 0) {
				auto item = items[i];
				for (size_t j = i; j > 0; --j) {
					items[j] = items[j - 1];
				}

				items[0] = item;
			}

			return std::shared_ptr<Value>(new Value(items[0].value));
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {
		if (!isEmpty()) {
			
			int r = rank(key);
			if (r > -1) {
				for (int j = r+1; j < N; ++j) {
					items[j - 1] = items[j];
				}

				--N;
			}
		}
	}

	virtual bool contains(Key key) const {
		return rank(key) > -1;
	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual size_t size() const {
		return N;
	}

	iterator begin() {
		return items.begin();
	}

	const_iterator begin() const {
		return items.cbegin();
	}

	const_iterator cbegin() const {
		return items.cbegin();
	}

	iterator end() {
		return items.begin() + size();
	}

	const_iterator end() const {
		return items.cbegin() + size();
	}

	const_iterator cend() const {
		return items.cbegin() + size();
	}



protected:
	void resize(size_t capacity) {
		if (capacity > 0) {
			items.resize(capacity);
		}
	}

	int rank(Key key) const {
		int r = -1;
		for (int i = 0; i < size(); ++i) {
			if (items[i].key == key) {
				r = i;
				break;
			}
		}

		return r;
	}
};

