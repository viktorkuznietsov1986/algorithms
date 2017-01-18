
#include "KeyIndexedCountingForQueue.h"
#include <array>

const int alphabetCount = 256;

void KeyIndexedCountingForQueue::sort(std::vector<std::queue<char>>& a) {
	std::array<int, alphabetCount + 1> characters;
	for (int i = 0; i < characters.size(); ++i)
		characters[i] = 0;

	std::vector<std::queue<char>> aux;
	aux.resize(a.size());

	for (int i = 0; i < a.size(); ++i) {
		auto c = static_cast<int>(a[i].front());
		++characters[c+1];
	}

	for (int r = 0; r < alphabetCount; ++r) {
		characters[r + 1] += characters[r];
	}

	for (int i = 0; i < a.size(); ++i) {
		auto c = static_cast<int>(a[i].front());
		auto pos = characters[c];
		++characters[c];

		aux[pos] = a[i];
	}

	for (int i = 0; i < a.size(); ++i) {
		a[i] = aux[i];
	}
}
