#pragma once

#include <vector>
#include <cassert>

const int INITIAL_ARRAY_SIZE = 30;

template <typename T>
class ThreeStacks
{
public:
	ThreeStacks() : _size1(0), _size2(0), _size3(0) {
		buffer.resize(INITIAL_ARRAY_SIZE);

		_position1 = 0;
		_position2 = 10;
		_position3 = 20;
	}

	~ThreeStacks() {

	}

	size_t size1() const { return _size1; }
	size_t size2() const { return _size2; }
	size_t size3() const { return _size3; }



	void push1(T t) {
		buffer[_position1 + _size1] = t;
		++_size1;

		// need to do the resize if _size1 is 10
	}

	void push2(T t) {
		buffer[_position2 + _size2] = t;
		++_size2;
	}

	void push3(T t) {
		buffer[_position3 + _size3] = t;
		++_size3;
	}

	T pop1() {
		assert(size1() > 0);

		auto value = buffer[_position1 + _size1 - 1];
		--_size1;

		return value;
	}

	T pop2() {
		assert(size2() > 0);

		auto value = buffer[_position2 + _size2 - 1];
		--_size2;

		return value;
	}

	T pop3() {
		assert(size3() > 0);

		auto value = buffer[_position3 + _size3 - 1];
		--_size3;

		return value;
	}

	bool empty1() const { return size1() == 0; }
	bool empty2() const { return size2() == 0; }
	bool empty3() const { return size3() == 0; }


private:
	size_t _size1;
	size_t _size2;
	size_t _size3;

	size_t _position1;
	size_t _position2;
	size_t _position3;

	std::vector<T> buffer;
};

