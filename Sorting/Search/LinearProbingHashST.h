#pragma once
#include "HashSymbolTableBase.h"

#include <vector>
#include <memory>

template <typename Key, typename Value>
class LinearProbingHashST :
	public HashSymbolTableBase<Key, Value>
{
private:
	std::vector<std::shared_ptr<Key>> keys;
	std::vector<std::shared_ptr<Value>> values;
	size_t numberOfDeletedValues;

	void resize(size_t nSize) {
		LinearProbingHashST st(nSize);

		for (size_t i = 0; i < M; ++i)
		{
			if (keys[i] != nullptr && values[i] != nullptr) {
				st.put(*(keys[i]), *(values[i]));
			}
		}

		keys = st.keys;
		values = st.values;
		M = st.M;
		numberOfDeletedValues = 0;

	}

	LinearProbingHashST(int m) : HashSymbolTableBase(m) {
		keys.reserve(M);
		for (size_t i = 0; i < M; ++i) {
			keys.push_back(std::shared_ptr<Key>(nullptr));
		}

		values.resize(M);
		numberOfDeletedValues = 0;
	}

public:


	LinearProbingHashST() : LinearProbingHashST(16) {
		
	}

	~LinearProbingHashST() {

	}

	virtual void put(Key key, Value val) {
		if (N > M / 2)
			resize(M * 2);
		else if (numberOfDeletedValues >= N / 4)
			resize(M);

		size_t i = hash(key);
		for (i; keys[i] != nullptr; i = (i + 1) % M) {
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
		size_t i = hash(key);

		for (i; keys[i] != nullptr; i = (i + 1) % M) {
			if (*keys[i] == key) {
				return values[i];
			}
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {

		if (!contains(key))
			return;

		size_t i = hash(key);

		for (i; keys[i] != nullptr; i = (i + 1) % M) {
			if (*keys[i] == key) {
				keys[i] = std::shared_ptr<Key>(nullptr);
				--N;
				break;
			}
		}

		++i;

		for (i; keys[i] != nullptr; i = (i + 1) % M) {
			auto k = *keys[i];
			auto v = *values[i];
			keys[i] = std::shared_ptr<Key>(nullptr);
			--N;
			put(k, v);
		}

		if (N > 0 && N <= M / 8)
			resize(M / 4);
	}

	void LazyDelete(Key key) {
		if (!contains(key))
			return;

		size_t i = hash(key);

		for (i; keys[i] != nullptr; i = (i + 1) % M) {
			if (*keys[i] == key) {
				values[i] = std::shared_ptr<Value>(nullptr);
				++numberOfDeletedValues;
				--N;
				break;
			}
		}

		if (N > 0) {
			if (N <= M / 8)
				resize(M / 4);
			else if (numberOfDeletedValues >= N / 4)
				resize(M);
		}
		

	}

	virtual bool contains(Key key) const {
		size_t i = hash(key);

		for (i; keys[i] != nullptr; i = (i + 1) % M) {
			if ((*keys[i] == key) && values[i] != nullptr) {
				return true;
			}
		}

		return false;
	}


};

