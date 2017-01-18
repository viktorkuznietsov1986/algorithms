#include "Table.h"



Table::Table() {
	for (int i = 0; i < 5; ++i) {
		chopsticks[i] = std::make_shared<Chopstick>();
	}

	for (int i = 0; i < 5; ++i) {
		auto leftIndex = i;
		auto rightIndex = i + 1;
		if (rightIndex == 5)
			rightIndex = 0;
		philosophers[i] = std::make_shared<Philosopher>(std::to_string(i), chopsticks[leftIndex], chopsticks[rightIndex]);
	}
}


Table::~Table() {
}

void Table::eat() {
	

	for (int i = 0; i < 5; ++i) {
		
		auto ph = philosophers[i];

		std::thread t([&ph] {	ph->eat(); 

								});

		t.join();
	}
}
