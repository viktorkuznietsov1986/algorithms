#pragma once
#include "ISymbolTable.h"


template <typename Key, typename Value>
class SequantialSearchST : public ISymbolTable<Key, Value>
{
private:
	struct Node {
		Node* next;
		Key key;
		Value value;

		Node(Key k, Value v, Node* n) {
			key = k;
			value = v;
			next = n;
		}
	};

public:
	SequantialSearchST() {
		first = nullptr;
		N = 0;
	}

	~SequantialSearchST() {
		auto node = first;
		while (node != nullptr) {
			auto n = node;
			node = node->next;
			delete n;
		}

		first = nullptr;
		N = 0;
	}

	virtual void put(Key key, Value val) {
		if (contains(key)) {
			getNode(key)->value = val;
		} 
		else {
			auto n = new Node(key, val, first);
			first = n;
			++N;
		}

		
	}

	virtual std::shared_ptr<Value> get(Key key) {
		return std::shared_ptr<Value>(new Value(getNode(key)->value));
	}

	virtual void Delete(Key key) {
		if (contains(key)) {
			Node* prev = nullptr;
			Node* curr = first;

			while (curr != nullptr)
			{
				if (curr->key == key) {
					if (prev != nullptr) {
						prev->next = curr->next;
						delete curr;
					}
					else {
						first = first->next;
						delete curr;
					}

					break;
				}

				prev = curr;
				curr = curr->next;
			}

			--N;
		}
	}

	virtual bool contains(Key key) const {
		auto n = first;

		while (n != nullptr) {
			if (n->key == key) {
				return true;
			}

			n = n->next;
		}

		return false;
	}

	virtual bool isEmpty() const {
		return size() == 0;
	}
	
	virtual size_t size() const {
		return N;
	}

	

protected:
	Node* getNode(Key key) {
		Node* n = first;

		while (n != nullptr) {
			if (n->key == key) {
				return n;
			}

			n = n->next;
		}

		return nullptr;
	}

private:
	
	Node* first;
	size_t N;
};

