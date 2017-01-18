#include "Alphabet.h"
#include <cmath>
#include <exception>
#include <cassert>

const int ExtendedASCII = 256;
const int Unicode16 = 65536;

Alphabet::Alphabet(const std::string& s) {
	r = s.size();
	lgr = static_cast<int>(log2(r));

	auto ridxsize = static_cast<size_t>(pow(2, lgr));
	if (ridxsize < ExtendedASCII) {
		ridxsize = ExtendedASCII;
	}
	else {
		ridxsize = Unicode16;
	}

	index = s;

	reverseIndex.resize(ridxsize);
	for (auto & ri : reverseIndex) {
		ri = -1;
	}

	for (int i = 0; i < s.size(); ++i) {
		auto c = s[i];
		if (reverseIndex[c] > -1) {
			throw std::exception("ctor. The alphabet symbol is not unique. Cannot proceed with the alphabet creation.");
		}
		else {
			reverseIndex[c] = i;
		}
	}
}


Alphabet::~Alphabet() {
}

char Alphabet::toChar(int index) const {
	assert(index >= 0 && index < this->index.size());
	return this->index[index];
}

int Alphabet::toIndex(char c) const {
	assert(c >= 0 && c < this->reverseIndex.size());
	return this->reverseIndex[c];
}

std::vector<int> Alphabet::toIndices(const std::string& s) const {
	std::vector<int> result;
	result.resize(s.size());

	for (int i = 0; i < s.size(); ++i) {
		if (!contains(s[i]))
			throw std::exception("Alphabet::toIndices: unknown symbol.");

		result[i] = toIndex(s[i]);
	}

	return result;
}

std::string Alphabet::toChars(const std::vector<int>& indices) const {
	std::string s;
	s.resize(indices.size());

	for (int i = 0; i < indices.size(); ++i) {
		s[i] = toChar(indices[i]);
	}

	return s;
}
