#include "SubstringBrute.h"


SubstringBrute::SubstringBrute(const std::string& pattern) : pat(pattern) {
}

SubstringBrute::~SubstringBrute() {
}

int SubstringBrute::search(const std::string& txt) const {
	return search(txt, 0);
}

std::list<int> SubstringBrute::searchAll(const std::string& txt) const {
	std::list<int> result;

	auto N = static_cast<int>(txt.length());
	auto M = static_cast<int>(pat.length());

	for (int startPos = 0; startPos < N - M + 1; startPos+=M) {
		startPos = search(txt, startPos);

		if (startPos < N - M + 1)
			result.push_back(startPos);
	}

	return result;
}

int SubstringBrute::search(const std::string& txt, int startPos) const {
	auto N = static_cast<int>(txt.length());
	auto M = static_cast<int>(pat.length());

	int i = startPos, j = 0;
	for (i = startPos, j = 0; i < N - M + 1 && j < M;) {
		if (txt[i + j] != pat[j]) {
			i = i - j + 1;
			j = 0;
		}
		else {
			if (j == M - 1) {
				return i;
			}
			++j;
		}

	}

	return N;
}

int SubstringBrute::count(const std::string& txt) const {
	return searchAll(txt).size();
}
