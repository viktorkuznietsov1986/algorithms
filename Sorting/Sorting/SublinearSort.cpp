#include "SublinearSort.h"
#include "InsertionSort.h"

#include <array>
#include <algorithm>


void SublinearSort::sort(std::vector<int>& a) {

	const int numberOfPasses = 2;
	const int numberOfPossibleValues = 256;
	const int shift = 8;
	std::vector<int> aux;
	aux.resize(a.size());
	

	for (int pass = 0; pass < numberOfPasses; ++pass) {
		std::array<int, numberOfPossibleValues + 1> counts;
		for (auto & value : counts) {
			value = 0;
		}

		for (auto value : a) {
			auto mask = static_cast<int>(0xF);
			auto valueToCount = static_cast<int>((value >> 2*(shift+pass)) & mask);

			++counts[valueToCount + 1];
		}

		for (int i = 1; i < counts.size(); ++i) {
			counts[i] += counts[i - 1];
		}

		for (int i = 0; i < a.size(); ++i) {
			auto value = a[i];
			auto mask = static_cast<int>(0xF);
			auto valueToCount = static_cast<int>((value >> 2 * (shift + pass)) & mask);
			aux[counts[valueToCount]++] = a[i];
		}

		std::copy(aux.begin(), aux.end(), a.begin());
	}

	InsertionSort::sort(a);
}
