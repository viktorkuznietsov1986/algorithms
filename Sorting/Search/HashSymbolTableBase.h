#pragma once
#include "ISymbolTable.h"
#include <functional>

template <typename Key, typename Value>
class HashSymbolTableBase : public ISymbolTable<Key, Value>
{
protected:
	int M;
	int N;

	size_t hash(Key k) const {
		size_t h = std::hash<Key>()(k);
		return (h & 0x7FFFFFFF) % M;
	}

	size_t hash1(Key k) const {
		return (11 * k) % M;
	}

	size_t hash2(Key k) const {
		return (17 * k) % M;
	}

	size_t hash3(Key k) const {
		size_t a = hash2(k);
		if (a == 0)
			++a;
		return a;
	}

public:


	HashSymbolTableBase(int m) : M(m), N(0) {

	}

	virtual ~HashSymbolTableBase() {

	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual size_t size() const {
		return N;
	}
};

