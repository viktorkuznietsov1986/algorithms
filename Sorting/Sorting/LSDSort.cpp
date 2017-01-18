#include "LSDSort.h"
#include "Alphabet.h"
#include <array>
#include <set>

const int asciiAlphabetLength = 256;

void LSDSort::sort(std::vector<std::string>& a, int w) {
	std::vector<std::string> aux;
	aux.resize(a.size());
	Alphabet chars(BASE64);

	for (int i = w - 1; i >= 0; --i) {
		//std::array<int, asciiAlphabetLength+1> characters;
		std::vector<int> characters;
		characters.resize(chars.R()+1);
		for (int& c : characters) {
			c = 0;
		}

		for (auto s : a) {
			//++characters[s[i] + 1];
			++characters[chars.toIndex(s[i]) + 1];
		}

		for (int j = 1; j < characters.size(); ++j) {
			characters[j] += characters[j - 1];
		}

		for (int j = 0; j < a.size(); ++j) {
			auto idx = characters[chars.toIndex(a[j][i])]++;
			aux[idx] = a[j];
			//aux[characters[a[j][i]]++] = a[j];
		}

		for (int j = 0; j < a.size(); ++j) {
			a[j] = aux[j];
		}
	}
}

void LSDSort::sort(std::vector<std::string>& a) {
	std::vector<std::string> aux;
	aux.resize(a.size());

	auto maxlen = static_cast<int>(0);

	for (auto s : a) {
		auto length = s.size();

		if (length > maxlen) {
			maxlen = length;
		}
		
	}

	for (int w = maxlen - 1; w >= 0; --w) {
		
		std::array<int, asciiAlphabetLength + 2> characters;

		for (int& c : characters) {
			c = 0;
		}

		for (auto s : a) {
			if (s.size() < w) {
				++characters[1];
			}
			else {
				auto c = s[w];
				++characters[c + 2];
			}
		}

		for (int i = 1; i < characters.size(); ++i) {
			characters[i] += characters[i - 1];
		}

		for (int i = 0; i < a.size(); ++i) {
			if (a[i].size() < w) {
				aux[characters[0]++] = a[i];
			}
			else {
				aux[characters[a[i][w] + 1]++] = a[i];
			}
		}

		for (int i = 0; i < a.size(); ++i) {
			a[i] = aux[i];
		}
	}
}