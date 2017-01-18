#pragma once
#include "HashSymbolTableBase.h"
#include "SequantialSearchST.h"

#include <vector>

template <typename Key, typename Value>
class SeparateChainingHashST : public HashSymbolTableBase<Key, Value>
{
private:
	std::vector<SequantialSearchST<Key, Value> > st;

public:
	SeparateChainingHashST() : SeparateChainingHashST(997) {
	}

	SeparateChainingHashST(int m) : HashSymbolTableBase(m) {
		st.resize(M);
	}

	~SeparateChainingHashST() {

	}

	virtual void put(Key key, Value val) {
		size_t tSize = st[hash(key)].size();
		st[hash(key)].put(key, val);

		if (st[hash(key)].size() > tSize)
			++N;
	}

	virtual std::shared_ptr<Value> get(Key key) {
		return st[hash(key)].get(key);
	}

	virtual void Delete(Key key) {
		
		size_t tSize = st[hash(key)].size();
		st[hash(key)].Delete(key);

		if (st[hash(key)].size() < tSize)
			--N;
	}

	virtual bool contains(Key key) const {
		return st[hash(key)].contains(key);
	}

	
};

