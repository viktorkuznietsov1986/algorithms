#pragma once
#include "HashSymbolTableBase.h"
#include "SequantialSearchST.h"

#include <vector>

template <typename Key, typename Value>
class DoubleProbingHashST :
	public HashSymbolTableBase<Key, Value>
{
private:
	std::vector<SequantialSearchST<Key, Value> > st;

protected:
	DoubleProbingHashST(int m) : HashSymbolTableBase(m) {
		st.resize(m);
	}

public:
	DoubleProbingHashST() : DoubleProbingHashST(3) {

	}

	virtual ~DoubleProbingHashST() {

	}

	virtual void put(Key key, Value val) {
		size_t size1 = st[hash1(key)].size();
		size_t size2 = st[hash2(key)].size();

		if (size1 <= size2) {
			st[hash1(key)].put(key, val);

			if (st[hash1(key)].size() > size1)
				++N;
		}
		else {
			st[hash2(key)].put(key, val);

			if (st[hash(key)].size() > size2)
				++N;
		}

		
	}

	virtual std::shared_ptr<Value> get(Key key) {
		auto h1 = hash1(key);
		auto h2 = hash2(key);

		if (st[h1].contains(key))
			return st[h1].get(key);

		return st[h2].get(key);
	}

	virtual void Delete(Key key) {
		auto h1 = hash1(key);
		auto h2 = hash2(key);
		
		size_t size2 = st[h2].size();
		
		if (st[h1].contains(key)) {
			size_t size = st[h1].size();
			st[h1].Delete(key);
			if (st[h1].size() < size)
				--N;
		}
		else {
			size_t size = st[h2].size();
			st[h2].Delete(key);
			if (st[h2].size() < size)
				--N;
		}


		
	}

	virtual bool contains(Key key) const {
		return st[hash(key)].contains(key);
	}
};

