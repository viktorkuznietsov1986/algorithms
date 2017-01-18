#pragma once
#include "HashSymbolTableBase.h"

#include <vector>
#include <memory>

template <typename Key, typename Value>
class DoubleHashingLPHashST :
	public HashSymbolTableBase<Key, Value>
{
private:
	std::vector<std::shared_ptr<Key>> keys;
	std::vector<std::shared_ptr<Value>> values;

	void resize(size_t nSize) {
		DoubleHashingLPHashST st(nSize);

		for (size_t i = 0; i < M; ++i)
		{
			if (keys[i] != nullptr && values[i] != nullptr) {
				st.put(*(keys[i]), *(values[i]));
			}
		}

		keys = st.keys;
		values = st.values;
		M = st.M;

	}

	DoubleHashingLPHashST(int m) : HashSymbolTableBase(m) {
		keys.reserve(M);
		for (size_t i = 0; i < M; ++i) {
			keys.push_back(std::shared_ptr<Key>(nullptr));
		}

		values.resize(M);
		
	}

public:
	DoubleHashingLPHashST() : DoubleHashingLPHashST(11) {

	}

	virtual ~DoubleHashingLPHashST() {

	}

	virtual void put(Key key, Value val) {
		if (N > M / 2)
			resize(M * 2);

		size_t i = hash1(key);
		size_t k = hash3(key);
		for (i; keys[i] != nullptr; i = (i + k) % M) {
			if (*keys[i] == key) {
				*values[i] = val;
				return;
			}
		}

		keys[i] = std::shared_ptr<Key>(new Key(key));
		values[i] = std::shared_ptr<Value>(new Value(val));
		++N;
	}

	virtual std::shared_ptr<Value> get(Key key) {
		size_t i = hash1(key);
		size_t k = hash3(key);

		for (i; keys[i] != nullptr; i = (i + k) % M) {
			if (*keys[i] == key) {
				return values[i];
			}
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {

		if (!contains(key))
			return;

		size_t i = hash1(key);
		size_t k = hash3(key);

		for (i; keys[i] != nullptr; i = (i + k) % M) {
			if (*keys[i] == key) {
				keys[i] = std::shared_ptr<Key>(nullptr);
				--N;
				break;
			}
		}

		++i;

		for (i; keys[i] != nullptr; i = (i + k) % M) {
			auto k = *keys[i];
			auto v = *values[i];
			keys[i] = std::shared_ptr<Key>(nullptr);
			--N;
			put(k, v);
		}

		if (N > 0 && N <= M / 8)
			resize(M / 4);
	}

	virtual bool contains(Key key) const {
		size_t i = hash1(key);
		size_t k = hash3(key);

		for (i; keys[i] != nullptr; i = (i + k) % M) {
			if ((*keys[i] == key)) {
				return true;
			}
		}

		return false;
	}
};

