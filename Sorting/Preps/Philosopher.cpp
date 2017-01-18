#include "Philosopher.h"

#include <iostream>



void Philosopher::eat() {
	if (leftChopstick->get()) {

		if (rightChopstick->get()) {

			std::cout << "Philosopher " << name << " has started eating." << std::endl;

			std::cout << "Philosopher " << name << " has stopped eating." << std::endl;

			rightChopstick->release();

		}
		
		leftChopstick->release();
		
	}
}
