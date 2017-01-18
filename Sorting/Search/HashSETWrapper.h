#pragma once
#include "ISet.h"
#include "LinearProbingHashST.h"

template <typename Key>
class HashSETWrapper :
	public ISet<Key>
{
private:
	std::shared_ptr<LinearProbingHashST<Key, int>> st;

public:
	HashSETWrapper() : st(std::make_shared < LinearProbingHashST<Key, int>>()) {
		
	}

	~HashSETWrapper() {

	}

	virtual void add(Key key) {
		st->put(key, 0);
	}

	virtual void Delete(Key key) {
		st->Delete(key);
	}

	virtual bool contains(Key key) const {
		return st->contains(key);
	}

	virtual size_t size() const {
		return st->size();
	}
};

