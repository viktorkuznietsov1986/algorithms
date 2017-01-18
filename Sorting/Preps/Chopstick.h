#pragma once
#include <mutex>

class Chopstick
{
public:
	Chopstick();
	virtual ~Chopstick();

	bool get();
	void release();

private:
	std::mutex m;
};

