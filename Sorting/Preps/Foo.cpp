#include "Foo.h"

#include <iostream>


void Foo::first() {
	_first.unlock();

	std::cout << "first" << std::endl;
}

void Foo::second() {
	std::lock_guard<std::mutex> lock(_first);
	_second.unlock();

	std::cout << "second" << std::endl;
}

void Foo::third() {
	std::lock_guard<std::mutex> lock(_second);

	std::cout << "third" << std::endl;
}
