#pragma once

#include "Philosopher.h"

#include <array>
#include <memory>
#include <thread>

class Table
{
	
public:
	Table();
	virtual ~Table();

	void eat();

protected:
	std::array<std::shared_ptr<Chopstick>, 5> chopsticks;
	std::array<std::shared_ptr<Philosopher>, 5> philosophers;
};

