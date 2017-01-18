#include "Chopstick.h"



Chopstick::Chopstick() {
}


Chopstick::~Chopstick() {
}

bool Chopstick::get() {
	if (m.try_lock()) {
		return true;
	}

	return false;
}

void Chopstick::release()  {
	m.unlock();
}
