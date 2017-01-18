#pragma once
#include <cassert>
#include "IMaxPQ.h"

template <typename T>
class OrderedLinkedListMaxPQ : public IMaxPQ<T>
{
public:
	OrderedLinkedListMaxPQ() {
		_size = 0;
		_first = _last = nullptr;
	}

	~OrderedLinkedListMaxPQ() {
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

		return std::shared_ptr<T>(new T(_first->data));
	}

	virtual std::shared_ptr<T> delMax() {
		assert(_size > 0);

		std::shared_ptr<T> retVal(new T(_first->data));

		Node<T>* n = _first;
		_first = _first->next;

		delete n;
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
			
			Node<T>* max = _first;
			
			while (max->data > n->data) {
				max = max->next;
			}

			n->prev = max->prev;
			max->prev = n;
			n->next = max;

			if (max == _first)
				_first = n;
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

