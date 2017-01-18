#pragma once
#include <stack>

template <typename T>
class QueueFrom2Stacks
{
public:
	QueueFrom2Stacks() : _size(0) {

	}

	~QueueFrom2Stacks() {

	}

	void enqueue(T t) {
		addStack.push(t);
		++_size;
	}

	T dequeue() {
		assert(_size > 0);

		if (removeStack.empty()) {
			while (addStack.size()) {
				auto element = addStack.top();
				removeStack.push(element);
				addStack.pop();
			}
		}

		auto element = removeStack.top();
		removeStack.pop();
		--_size;

		return element;
	}

	size_t size() const { return _size; }
	bool isEmpty() const { return size() == 0; }

private:
	std::stack<T> addStack;
	std::stack<T> removeStack;
	size_t _size;
};

