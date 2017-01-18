#pragma once

#include <mutex>

class Foo
{
public:
	Foo() { _first.lock();
			_second.lock();
				}
	~Foo() {}

	void first();
	void second();
	void third();

private:
	std::mutex _first;
	std::mutex _second;
	std::mutex _third;
};

