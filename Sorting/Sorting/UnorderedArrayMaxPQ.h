#pragma once
#include "PriorityQueue.h"
#include "IMaxPQ.h"
#include <cassert>
template <typename T>
class CUnorderedArrayMaxPQ : public IMaxPQ<T>
{
public:
	CUnorderedArrayMaxPQ(int N) {
		assert(N > 0);

		arr = new T[N];
		arrSize = N;
		_size = 0;
	}

	CUnorderedArrayMaxPQ(const CUnorderedArrayMaxPQ& other) : arrSize(other.arrSize), _size(other.size()) {
		arr = new T[arrSize];

		std::copy(other.arr, other.arr + _size, arr);
	}

	CUnorderedArrayMaxPQ(CUnorderedArrayMaxPQ&& other) : arrSize(other.arrSize), arr(other.arr), _size(other.size()) {
		other.arr = nullptr;
		other.arrSize = 0;
		other._size = 0;
	}

	CUnorderedArrayMaxPQ& operator=(CUnorderedArrayMaxPQ& other) {
		if (this != &other) {
			delete[] arr;

			arrSize = other.arrSize;
			arr = new T[arrSize];
			_size = other.size();

			std::copy(other.arr, other.arr + _size, arr);
		}

		return *this;
	}

	CUnorderedArrayMaxPQ& operator=(CUnorderedArrayMaxPQ&& other) {
		if (this != &other) {
			delete[] arr;

			arr = other.arr;
			arrSize = other.arrSize;
			_size = other._size;

			other.arr = nullptr;
			other.arrSize = 0;
			other._size = 0;
		}

		return *this;
	}

	~CUnorderedArrayMaxPQ() {
		if (arr) {
			delete[] arr;
		}
	}

	virtual void insert(const T& item) {
		if (size() == arrSize) {
			resize(arrSize * 2);
		}

		arr[_size++] = item;
	}

	virtual std::shared_ptr<T> max() const {
		if (!size()) {
			// throw 
		}

		return std::shared_ptr<T>(new T(arr[findMVIndex()]));
	}

	virtual std::shared_ptr<T> delMax() {
		if (!size()) {
			// throw
		}

		size_t mvIndex = findMVIndex();
		std::shared_ptr<T> rv(new T(arr[mvIndex]));

		std::swap(arr[mvIndex], arr[--_size]);

		if (size() < arrSize / 4) {
			resize(arrSize / 4);
		}

		return rv;
	}

	virtual size_t size() const {
		return _size;
	}

	virtual bool isEmpty() const {
		return _size == 0;
	}

protected:

	void resize(size_t capacity) {
		if (capacity <= 0) {
			// throw an exception
		}

		T* nArr = new T[capacity];
		std::copy(arr, arr + size(), nArr);

		delete[] arr;
		arr = nArr;
		arrSize = capacity;
	}
	
	size_t findMVIndex() const {
		T mv = arr[0];
		size_t index = 0;

		for (size_t i = 1; i < size(); ++i) {
			if (mv < arr[i]) {
				mv = arr[i];
				index = i;
			}
		}

		return index;
	}

private:
	T* arr;
	size_t arrSize;
	size_t _size;
};

