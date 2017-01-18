#pragma once
#include "ISymbolTable.h"

template <typename Key, typename Value>
class IIndexedSymbolTable : public ISymbolTable<Key, Value>
{
public:
	virtual int rank(Key key) const = 0;
	virtual Key min() const = 0;
	virtual Key max() const = 0;
	virtual Key ceiling(Key key) const = 0; // smallest key greater or equal to key
	virtual Key floor(Key key) const = 0; // largest key smaller or equal to key
	using ISymbolTable<Key, Value>::size;
	virtual int size(Key lo, Key hi) const = 0;
	virtual Key select(int k) const = 0; // select key of rank k
	virtual void deleteMin() = 0;
	virtual void deleteMax() = 0;
};

