#pragma once
#include <cassert>
#include <memory>

#include "IMaxPQ.h"

template <typename T>
class UnorderedLinkedListMaxPQ : public IMaxPQ<T> {

public:
	UnorderedLinkedListMaxPQ() {
		_size = 0;
		_first = _last = nullptr;
	}

	~UnorderedLinkedListMaxPQ() {
		while (_first) {
			Node<T>* n = _first;
			_first = _first->next;
			delete n;
		}

		_size = 0;
		_last = nullptr;
	}

	virtual std::shared_ptr<T> max() const {
		assert(_size > 0);
		
		Node<T>* n = _first;
		T max = n->data;
		
		while (n) {
			if (max < n->data) {
				max = n->data;
			}

			n = n->next;
		}

		return std::shared_ptr<T>(new T(max));
	}

	virtual std::shared_ptr<T> delMax() {
		assert(_size > 0);

		Node<T>* max = _first;
		Node<T>* n = _first;

		while (n) {
			if (max->data < n->data) {
				max = n;
			}

			n = n->next;
		}

		std::shared_ptr<T> retVal(new T(max->data));

		if (max->prev) {
			max->prev->next = max->next;
		}

		delete max;
		--_size;

		if (_size == 0) {
			_first = nullptr;
			_last = nullptr;
		}

		return retVal;

	}

	virtual void insert(const T& item) {
		if (!_first) {
			_first = new Node<T>(item);
			_last = _first;
		}
		else {
			Node<T>* n = new Node<T>(item);
			_last->next = n;
			n->prev = _last;
			_last = n;
		}

		++_size;
	}

	virtual size_t size() const {
		return _size;
	}

	virtual bool isEmpty() const {
		return _size == 0;
	}

private:
	template <typename T>
	struct Node {
		Node(const T& item, Node* n = nullptr, Node* p = nullptr) : data(item), next(n), prev(p) {
			
		}

		Node(const Node& node) = delete;
		Node(Node&& node) = delete;
		Node& operator=(const Node& node) = delete;

		T data;
		Node* next;
		Node* prev;
	};

	Node<T>* _first;
	Node<T>* _last;
	int _size;
};

