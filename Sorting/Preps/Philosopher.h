#pragma once

#include <memory>
#include <string>

#include "Chopstick.h"

class Philosopher
{
public:
	Philosopher(const std::string& n, std::weak_ptr<Chopstick> left, std::weak_ptr<Chopstick> right) : name(n), leftChopstick(left), rightChopstick(right) {}
	virtual ~Philosopher() {}

	void eat();

private:
	std::shared_ptr<Chopstick> leftChopstick;
	std::shared_ptr<Chopstick> rightChopstick;
	std::string name;
};

