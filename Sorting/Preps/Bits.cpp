#include "Bits.h"

#include <vector>
#include <cassert>

std::string Int32ToString(int value) {
	int mask = 1;

	std::string result;

	for (int i = 0; i < 32; ++i) {
		if (value & mask) {
			result = "1" + result;
		}
		else {
			result = "0" + result;
		}

		mask = mask << 1;
	}

	return result;
}

int getBit(int N, int position) {
	int mask = 1 << position;

	if ((N & mask) == mask)
		return 1;

	return 0;
}

void setBit(int* N, int position) {
	assert(N != nullptr);
	assert(position >= 0 && position < 32);

	int mask = 1 << position;

	*N |= mask;
}

void cleanBit(int* N, int position) {
	assert(N != nullptr);
	assert(position >= 0 && position < 32);

	int mask = ~(1 << position);

	*N &= mask;
}

void setBitValue(int* N, int position, int value) {
	assert(N != nullptr);
	assert(position >= 0 && position < 32);
	assert(value == 0 || value == 1);

	if (value == 1) {
		setBit(N, position);
	}
	else {
		cleanBit(N, position);
	}
}

int injectOneIntToAnother(int N, int M, int i, int j) {
	
	int result = N;

	if (i < j) {
		for (int k = i; k <= j; ++k) {
			setBitValue(&result, k, getBit(M, k - i));
		}
	}

	return result;
}

int flipBit(int N) {

	int zeroPos = -1;
	int countOfOnes = 0;
	int maxCountOfOnes = 0;

	bool firstOccurrenceHappened = false;

	for (int i = 0; i < 32; ++i) {
		int bit = getBit(N, i);

		if (bit == 0) {

			if (firstOccurrenceHappened) {
				firstOccurrenceHappened = false;
				i = zeroPos;

				if (maxCountOfOnes < countOfOnes) {
					maxCountOfOnes = countOfOnes;
				}
				countOfOnes = 0;

				continue;
			}
			else {
				zeroPos = i;
				firstOccurrenceHappened = true;
			}
		}
		
		++countOfOnes;
	}

	if (maxCountOfOnes < countOfOnes) {
		maxCountOfOnes = countOfOnes;
	}

	return maxCountOfOnes;

}

std::string floatToBit(float value) {
	int val = *(int*)(&value);

	std::string result;

	for (int i = 0; i < 32; ++i) {
		if ((1 << i) & val) {
			result = "1" + result;
		}
		else {
			result = "0" + result;
		}
	}

	return result;
}

std::string doubleToBit(double value) {
	long long val = *(long long*)(&value);

	std::string result;

	for (long long i = 0; i < 64; ++i) {
		if (((long long)1 << i) & val) {
			if (i >= 32) {
				result = "#ERROR";
				break;
			}

			result = "1" + result;
		}
		else {
			result = "0" + result;
		}
	}

	return result;
}