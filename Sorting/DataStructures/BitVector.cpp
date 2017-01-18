#include "BitVector.h"



BitVector::BitVector(int N) : _size(0) {
	auto vecSize = N / sizeof(int) + 1;
	_data.resize(vecSize);

	for (auto& i : _data) {
		i = 0;
	}
}


BitVector::~BitVector() {
}

void BitVector::add(int x) {
	auto majorPos = getMajorPos(x);
	auto minorPos = getMinorPos(x);

	if (!isSet(majorPos, minorPos)) {
		setBit(majorPos, minorPos);
		++_size;
	}
}

void BitVector::remove(int x) {
	auto majorPos = getMajorPos(x);
	auto minorPos = getMinorPos(x);

	if (isSet(majorPos, minorPos)) {
		clearBit(majorPos, minorPos);
		--_size;
	}
}

bool BitVector::contains(int x) const {
	auto majorPos = getMajorPos(x);
	auto minorPos = getMinorPos(x);

	return isSet(majorPos, minorPos);
}

std::vector<int> BitVector::getSortedIntArray() const {
	std::vector<int> result;
	result.reserve(_size);

	for (int majorPos = 0; majorPos < _data.size(); ++majorPos) {
		for (int minorPos = 0; minorPos < sizeof(int); ++minorPos) {
			if (isSet(majorPos, minorPos)) {
				result.push_back(sizeof(int)*majorPos + minorPos);
			}
		}
	}

	return result;
}

bool BitVector::isSet(int majorPos, int minorPos) const {
	auto mask = static_cast<int>(createMask(minorPos));
	return _data[majorPos] & mask;
}

void BitVector::setBit(int majorPos, int minorPos) {
	auto mask = static_cast<int>(createMask(minorPos));
	_data[majorPos] |= mask;
}

void BitVector::clearBit(int majorPos, int minorPos) {
	auto mask = static_cast<int>(createMask(minorPos));
	mask ^= mask;
	_data[majorPos] &= mask;
}

