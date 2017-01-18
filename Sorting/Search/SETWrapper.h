#pragma once
#include "ISet.h"
#include "RedBlackBST.h"

template <typename Key>
class SETWrapper : public ISet<Key>
{
private:
	std::shared_ptr<RedBlackBST<Key,int>> st;

public:
	SETWrapper() : SETWrapper(std::make_shared<RedBlackBST<Key, int>>()) {

	}

	SETWrapper(std::shared_ptr<RedBlackBST<Key, int>>& s) {
		st = s;
	}

	virtual ~SETWrapper() {

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

