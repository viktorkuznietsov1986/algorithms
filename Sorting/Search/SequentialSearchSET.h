#pragma once
#include "ISet.h"

template <typename Key>
class SequentialSearchSET :
	public ISet<Key>
{
private:
	struct Node {
		Node* next;
		Key key;

		Node(Key k, Node* n) {
			key = k;
			next = n;
		}
	};

	Node* first;
	size_t N;

public:
	SequentialSearchSET() {
		first = nullptr;
		N = 0;
	}

	virtual ~SequentialSearchSET() {
		auto node = first;
		while (node != nullptr) {
			auto n = node;
			node = node->next;
			delete n;
		}

		first = nullptr;
		N = 0;
	}

	virtual void add(Key key) {
		if (contains(key))
			return;

		first = new Node(key, first);
		++N;
	}

	virtual void Delete(Key key) {
		Node* x = first;
		Node* prev = nullptr;

		while (x != nullptr) {
			if (x->key == key) {
				
				if (prev != nullptr) {
					prev->next = x->next;
					delete x;
				}
				else if (x == first) {
					first = first->next;
				}
				--N;
				break;
			}

			prev = x;
			x = x->next;
		}
	}

	virtual bool contains(Key key) const {
		auto x = first;

		while (x != nullptr) {
			if (x->key == key)
				return true;

			x = x->next;
		}

		return false;
	}

	virtual size_t size() const {
		return N;
	}

protected:

};

