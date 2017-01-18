#pragma once
#include <memory>
#include <cassert>
#include <unordered_set>
#include <iostream>

template <typename T>
class List
{
class Node;

public:
	List() {
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	~List() {
		auto node = first;

		while (node != nullptr) {

			auto n = node;
			node = node->next;
			delete n;
		}
	}

	void AddFirst(const T& item) {
		auto n = new Node();
		n->data = item;
		if (first == nullptr) {
			first = n;
			first->next = nullptr;
			last = first;
		}
		else {
			n->next = first;
			first = n;
		}

		++size;
	}

	void AddLast(const T& item) {
		if (first == nullptr) {
			AddFirst(item);
		}
		else {
			auto n = new Node();
			n->data = item;
			n->next = nullptr;
			last->next = n;
			last = n;
			++size;
		}
	}

	void InsertAt(const T& item, size_t pos) {

	}

	void DeleteAt(size_t pos) {

	}

	void Sort() {
		assert(!isEmpty());
		Node* nFirst = nullptr;

		auto node = first;

		while (node != nullptr) {
			auto nnode = node;
			nnode->next = nullptr;
			node = node->next;
			nFirst = merge(nFirst, nnode);
		}

		first = nFirst;
	}

	T& operator[](std::size_t idx) {
		assert(idx >= 0 && idx < size);

		auto node = first;

		for (size_t i = 1; i <= idx; ++i) {
			node = node->next;
		}

		return node->data;
	}

	const T& operator[](std::size_t idx) const {
		assert(idx >= 0 && idx < size);

		auto node = first;

		for (size_t i = 1; i <= idx; ++i) {
			node = node->next;
		}

		return node->data;
	}

	size_t Size() const {
		return size;
	}

	bool isEmpty() const {
		return size == 0;
	}

	void removeDuplicates() {
		auto buffer = std::make_unique<std::unordered_set<T>>();

		auto n = first;
		Node* nprev = nullptr;

		while (n) {
			if (buffer->find(n->data) != buffer->cend()) {
				// remove element
				auto next = n->next;
				if (nprev == nullptr) {
					first = next;
				}
				else {
					nprev->next = next;
				}

				delete n;

				n = next;

				--size;

			}
			else {
				buffer->emplace(n->data);
				nprev = n;
				n = n->next;
			}
		}
	}

	void partition(T t) {
		/*Node* beforeT = nullptr;
		Node* lastT = nullptr;
		Node* afterT = nullptr;
		auto n = first;
		Node* nfirst = nullptr;

		while (n != nullptr) {
			auto next = n->next;
			
			if (nfirst == nullptr) {
				nfirst = n;
				nfirst->next = nullptr;

				if (nfirst->data < t)
					beforeT = nfirst;
				else if (nfirst->data == t)
					lastT = nfirst;
				else
					afterT = nfirst;

			}
			else {
				n->next = nullptr;

				if (n->data < t) {
					if (beforeT == nullptr) {
						beforeT = n;
						
						if (lastT != nullptr)
							beforeT->next = lastT;
						else if (afterT != nullptr)
							beforeT->next = afterT;

						nfirst = beforeT;
					}
					else {
						
						n->next = beforeT->next;
						beforeT->next = n;
						beforeT = n;
					}
				}
				else if (n->data == t) {
					if (lastT == nullptr) {
						lastT = n;
						if (beforeT != nullptr) {
							beforeT->next = lastT;
						}
						else {
							nfirst->next = lastT->next;
							nfirst = lastT;
						}

						
					}
					else {
						n->next = lastT->next;
						lastT->next = n;
						lastT = n;
					}
				}
				else {
					if (afterT == nullptr) {
						afterT = n;
						afterT->next = nullptr;

						if (lastT != nullptr) {
							lastT->next = afterT;

						}
						else {
							if (beforeT != nullptr) {
								beforeT->next = afterT;
							}
							else {
								nfirst->next = afterT->next;
								nfirst = lastT;
							}
						}
					}
					else {
						n->next = afterT->next;
						afterT->next = n;
						afterT = n;
					}
				}
			}

			n = next;

			
			
		}

		first = nfirst;*/

		Node* beforeStart = nullptr;
		Node* beforeEnd = nullptr;
		Node* afterStart = nullptr;
		Node* afterEnd = nullptr;

		auto node = first;

		while (node != nullptr) {
			auto next = node->next;
			node->next = nullptr;

			if (node->data < t) {
				if (beforeStart == nullptr) {
					beforeStart = node;
					beforeEnd = beforeStart;
				}
				else {
					beforeEnd->next = node;
					beforeEnd = node;
				}
			}
			else {
				if (afterStart == nullptr) {
					afterStart = node;
					afterEnd = afterStart;
				}
				else {
					afterEnd->next = node;
					afterEnd = node;
				}
			}

			node = next;
		}

		beforeEnd->next = afterStart;

		first = beforeStart;
	}

	bool isSorted() const {
		if (isEmpty()) {
			return false;
		}

		T data = first->data;
		auto next = first->next;

		while (next != nullptr) {
			if (data > next->data)
				return false;

			data = next->data;
			next = next->next;
		}

		return true;
	}


	friend std::ostream& operator<<(std::ostream& os, const List<T>& data) {
		auto n = data.first;

		os << "{";

		while (n) {

			os << n->data;

			n = n->next;

			if (n != nullptr)
				os << ", ";
		}

		os << "}";

		return os;
	}
	

protected:
	Node* getAt(size_t i) {
		assert(i >= 0);

		if (i >= Size())
			return nullptr;

		Node* item = first;
		for (size_t j = 0; j < i; ++j) {
			item = item->next;
		}

		return item;
	}

private:
	struct Node {
		Node* next;
		T data;
	};

	Node* merge(Node* l, Node* r) {
		if (r == nullptr)
			return l;

		if (l == nullptr)
			return r;

		Node*  result = nullptr;
		auto lnode = l;
		auto rnode = r;

		if (lnode->data <= rnode->data) {
			result = lnode;
			lnode = lnode->next;
			
		}
		else {
			result = rnode;
			rnode = rnode->next;
		}

		result->next = nullptr;

		while (true) {
			if (lnode == nullptr && rnode == nullptr) {
				break;
			}

			if (lnode == nullptr) {
				result->next = rnode;
				break;
			} 
			else if (rnode == nullptr) {
				result->next = lnode;
				break;
			}
			else if (lnode->data <= rnode->data) {
				result->next = lnode;
				lnode = lnode->next;
			}
			else {
				result->next = rnode;
				rnode = rnode->next;
			}

			result = result->next;
			result->next = nullptr;
		}

		return result;
	}

	Node* first;
	Node* last;
	size_t size;
};

//template <typename T>
//std::ostream& operator<<(std::ostream& os, const List<T>& data) {
//	auto n = data.first;
//
//	while (n) {
//
//		os << n->data << ", ";
//
//		n = n->next;
//	}
//
//	return os;
//}

