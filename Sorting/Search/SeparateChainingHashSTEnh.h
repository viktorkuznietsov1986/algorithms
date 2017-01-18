#pragma once
#include "HashSymbolTableBase.h"

#include <vector>
#include <memory>

template <typename Key, typename Value>
class SeparateChainingHashSTEnh :
	public HashSymbolTableBase<Key, Value>
{
private:
	struct Node {
		Node* next;
		Key key;
		Value value;
		int numberOfEntriesInserted;

		Node(Key k, Value v, Node* n, int number) : key(k), value(v), next(n), numberOfEntriesInserted(number) {
			
		}
	};

	std::vector<Node*> st;

public:
	SeparateChainingHashSTEnh() : SeparateChainingHashSTEnh(997) {
		
	}

	SeparateChainingHashSTEnh(int m) : HashSymbolTableBase(m) {
		st.reserve(M);

		for (size_t i = 0; i < M; ++i)
			st.push_back(nullptr);
	}

	SeparateChainingHashSTEnh(SeparateChainingHashSTEnh&&) = delete;
	SeparateChainingHashSTEnh(const SeparateChainingHashSTEnh&) = delete;
	SeparateChainingHashSTEnh& operator=(const SeparateChainingHashSTEnh&) = delete;

	~SeparateChainingHashSTEnh() {
		for (size_t i = 0; i < M; ++i) {
			auto x = st[i];

			while (x != nullptr) {
				auto t = x;
				x = x->next;
				delete t;
			}
		}
	}

	virtual void put(Key key, Value val) {
		auto i = hash(key);
		auto x = st[i];

		auto t = putNode(x, key, val);

		if (x != t) {
			++N;
			st[i] = t;
		}
	}

	virtual std::shared_ptr<Value> get(Key key) {
		auto i = hash(key);
		auto x = st[i];

		auto t = getNode(x, key);

		if (t) {
			return std::shared_ptr<Value>(new Value(t->value));
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {
		auto i = hash(key);
		auto x = st[i];
		auto t = deleteNode(x, key);

		st[i] = t;
	}

	virtual bool contains(Key key) const {
		auto i = hash(key);
		auto x = st[i];

		return nodeExists(x, key);
	}

	virtual size_t DeleteAllNodesWithEntriesCountGreater(int entryCount) {
		size_t count = 0;
		for (size_t i = 0; i < M; ++i) {
			auto x = st[i];
			auto first = x;

			while (x != nullptr) {
				if (x->numberOfEntriesInserted > entryCount) {
					auto t = x;
					x = x->next;
					if (t == first)
						first = nullptr;

					delete t;
					t = nullptr;
					--N;
					++count;
					continue;
				}

				x = x->next;
			}

			st[i] = first;
		}

		return count;
	}

protected:
	Node* deleteNode(Node* x, Key key) {

		auto first = x;
		auto prev = x;

		while (x) {
			if (x->key == key)
				break;

			prev = x;
			x = x->next;
		}

		if (x) {
			if (first == x) {
				first = x->next;
			}
			else {
				prev->next = x->next;
			}

			delete x;
			x = nullptr;

			--N;

			return first;

		}

		return nullptr;

	}

	Node* getNode(Node* x, Key key) {
		if (x == nullptr)
			return nullptr;

		while (x) {
			if (x->key == key)
				return x;

			x = x->next;
		}

		return nullptr;
	}

	bool nodeExists(Node* x, Key key) const {
		if (x == nullptr)
			return false;

		while (x) {
			if (x->key == key)
				return true;

			x = x->next;
		}

		return false;
	}

	Node* putNode(Node* x, Key key, Value val) {
		
		auto t = getNode(x, key);

		if (t) {
			t->value = val;
			return x;
		}

		return new Node(key, val, x, N);
	}
};

