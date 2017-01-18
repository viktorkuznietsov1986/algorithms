#pragma once
#include "IMaxPQ.h"
#include <cassert>

template <typename T>
class COrderedArrayMaxPQ : public IMaxPQ<T>
{
public:
	COrderedArrayMaxPQ(int N) {
		assert(N > 0);

		arr = new T[N];
		arrSize = N;
		_size = 0;
	}

	COrderedArrayMaxPQ(const COrderedArrayMaxPQ& other) : arrSize(other.arrSize), _size(other.size()) {
		arr = new T[arrSize];

		std::copy(other.arr, other.arr + _size, arr);
	}

	COrderedArrayMaxPQ(COrderedArrayMaxPQ&& other) : arrSize(other.arrSize), arr(other.arr), _size(other.size()) {
		other.arr = nullptr;
		other.arrSize = 0;
		other._size = 0;
	}

	COrderedArrayMaxPQ& operator=(COrderedArrayMaxPQ& other) {
		if (this != &other) {
			delete[] arr;

			arrSize = other.arrSize;
			arr = new T[arrSize];
			_size = other.size();

			std::copy(other.arr, other.arr + _size, arr);
		}

		return *this;
	}

	COrderedArrayMaxPQ& operator=(COrderedArrayMaxPQ&& other) {
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

	~COrderedArrayMaxPQ() {
		if (arr) {
			delete[] arr;
			arr = nullptr;
		}
	}

	virtual void insert(const T& item) {
		if (size() == arrSize) {
			resize(arrSize * 2);
		}

		int pos = 0;
		for (size_t i = 0; i < _size; ++i) {
			if (item < arr[i]) {
				break;
			}

			++pos;
		}

		for (int i = _size-1; i >= pos; --i) {
			arr[i + 1] = arr[i];
		}

		arr[pos] = item;
		++_size;
	}

	virtual std::shared_ptr<T> max() const {
		if (!size()) {
			// throw 
		}

		return std::shared_ptr<T>(new T(arr[_size-1]));
	}

	virtual std::shared_ptr<T> delMax() {
		if (!size()) {
			// throw
		}

		return std::shared_ptr<T>(new T(arr[--_size]));
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

private:
	T* arr;
	size_t arrSize;
	size_t _size;
};

