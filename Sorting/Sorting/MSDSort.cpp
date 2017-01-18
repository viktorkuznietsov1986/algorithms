#include "MSDSort.h"
#include "InsertionSort.h"
#include "Alphabet.h"
#include <array>

const int alphabetSize = 256;
const int maxInsertionSort = 15;


void MSDSort::sort(std::vector<std::string>& arr) {
	sort(arr, 0, arr.size() - 1, 0);
}

void MSDSort::sort(std::vector<std::string>& arr, int lo, int hi, int w) {
	if (lo >= hi) {
		return;
	}

	if (hi - lo <= maxInsertionSort) {
		InsertionSort::sort(arr, lo, hi, w);
		return;
	}
	
	std::array<int, alphabetSize + 2> characters;
	for (int & c : characters) {
		c = 0;
	}

	std::vector<std::string> aux;
	aux.resize(hi - lo + 1);

	int numberOfEmptyChars = 0;

	for (int i = lo; i <= hi; ++i) {
		if (arr[i].size() > w) {
			++characters[arr[i][w] + 2];
		}
		else {
			++numberOfEmptyChars;
		}
	}

	characters[0] = numberOfEmptyChars;

	for (int i = 1; i < characters.size(); ++i) {
		characters[i] += characters[i - 1];
	}

	int emptyCharsIdx = lo;

	for (int i = lo; i <= hi; ++i) {
		if (arr[i].size() < w) {
			arr[emptyCharsIdx++] = arr[i];
		}
		else {
			aux[characters[arr[i][w] + 1]++] = arr[i];
		}
		
	}

	for (int i = lo; i <= hi; ++i) {
		arr[i] = aux[i-lo];
	}

	for (int i = 1; i < characters.size(); ++i) {
		auto next = i;
		auto prev = i - 1;

		auto width = characters[next] - characters[prev];

		if (width > 1)
			sort(arr, characters[prev], characters[next]-1, w + 1);
	}


}
