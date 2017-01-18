#pragma once
#include "ISymbolTable.h"

template <typename Key, typename Value>
class OrderedSequentialSearchST :
	public ISymbolTable<Key, Value>
{

	struct Node {
		Key key;
		Value value;
		Node* next;

		Node(Key k, Value v, Node* n) : key(k), value(v), next(n) {}
	};
	

public:
	OrderedSequentialSearchST() {
		N = 0;
		first = nullptr;
	}
	
	~OrderedSequentialSearchST() {
		Node* n = first;

		while (n != nullptr) {
			Node* item = n;
			n = n->next;
			delete item;
		}
	}

	virtual void put(Key key, Value val) {
		auto node = getNode(key);
		if (node == nullptr) {
			if (first == nullptr) {
				first = new Node(key, val, nullptr);
			}
			else {
				if (first->key > key) {
					auto insNode = new Node(key, val, first);
					first = insNode;
				}
				else {
					auto insertAfter = first;
					for (auto n = first->next; n != nullptr; n = n->next) {
						if (n->key > key) {
							break;
						}

						insertAfter = n;
					}

					auto insNode = new Node(key, val, insertAfter->next);
					insertAfter->next = insNode;
				}
			}

			++N;
		}
		else {
			node->value = val;
		}
	}

	virtual std::shared_ptr<Value> get(Key key) {
		auto node = getNode(key);
		if (node != nullptr) {
			return std::shared_ptr<Value>(new Value(node->value));
		}

		return std::shared_ptr<Value>(nullptr);
	}

	virtual void Delete(Key key) {
		if (isEmpty())
			return;

		Node* prevNode = nullptr;
		Node* currNode = first;

		while (currNode != nullptr) {
			
			if (currNode->key == key) {
				break;
			}

			prevNode = currNode;
			currNode = currNode->next;
		}

		if (currNode == nullptr) {
			return;
		}

		if (prevNode == nullptr) {
			auto n = first;
			first = first->next;
			delete n;
		}
		else {
			auto n = currNode;
			prevNode->next = currNode->next;
			delete n;
		}

		--N;

	}

	virtual bool contains(Key key) const {
		Node* result = first;

		while (result != nullptr) {
			if (result->key == key) {
				break;
			}

			result = result->next;
		}

		return nullptr != result;
	}

	virtual bool isEmpty() const {
		return size() == 0;
	}

	virtual size_t size() const {
		return N;
	}

protected:
	Node* getNode(Key key) {
		Node* result = first;

		while (result != nullptr) {
			if (result->key == key) {
				break;
			}

			result = result->next;
		}

		return result;
	}

private:


	size_t N;
	Node* first;
};

