#include "different.h"

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include "Bits.h"
#include <algorithm>

#include <iostream>
#include <fstream>

void lastKLines(const char* fileName, int k) {
	assert(fileName != nullptr);

	FILE* f;
	fopen_s(&f, fileName, "r");

	if (!f) {
		std::cout << "ERROR!!!! Loading file failed" << std::endl;
	}
	else {
		
		char buff[256];

		std::queue<char*> q;

		while ( std::fgets(buff, 256, f) != NULL) {
			int len = strlen(buff);
			char* str = new char[len+1];
			strcpy_s(str, sizeof(char) * (len+1), buff);

			q.push(str);

			if (q.size() > k) {
				char* s = q.front();
				q.pop();
				delete[] s;
			}
		}

		fclose(f);

		while (q.size()) {
			std::cout << q.front() << std::endl;
			q.pop();
		}
	}

	
}


void reverse(char* str) {
	assert(str != nullptr);

	size_t len = strlen(str);
	for (size_t i = 0; i < len/2; ++i) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int** my2DAlloc(int rows, int columns) {
	int** memory = (int**)malloc(sizeof(int)*rows);

	for (int i = 0; i < rows; ++i)
		memory[i] = (int*)malloc(sizeof(int)*columns);

	return memory;
}

void myDeAlloc(int** arr, int rows) {
	assert(arr != nullptr);
	
	for (int i = 0; i < rows; ++i)
		free(arr[i]);

	arr = nullptr;
}

int tripleStep(int n) {
	/*if (n <= 0) {
		return 1;
	}

	if (n == 1) {
		return 1;
	}

	return tripleStep(n - 1) + tripleStep(n - 2) + tripleStep(n - 3);*/

	int* arr = (int*)malloc(sizeof(int)*(n+1));

	for (int i = 0; i <= n; ++i) {
		arr[i] = -1;
	}

	arr[0] = 1;
	arr[1] = 1;

	auto result = tripleStepRec(n, arr);

	free(arr);

	return result;
}

int tripleStepRec(int n, int* arr) {
	
	if (n <= 0) {
		return 1;
	}

	if (n == 1) {
		return 1;
	}

	if (arr[n] == -1) {
		arr[n] = tripleStepRec(n - 1, arr) + tripleStepRec(n - 2, arr) + tripleStepRec(n - 3, arr);
	}

	return arr[n];
}

int missingInt(const char* fileName) {
	if (fileName == nullptr)
		return -1; // or throw an exception!

	// todo read the file
	std::vector<int> bitVector;
	const int bitVectorSize = 67108864;
	const int bufferSize = 256;
	const int bitElementSize = 32;

	std::ifstream f;
	f.open(fileName);

	//if (f.eof())
	//	return -1; // or throw an exception!

	bitVector.resize(bitVectorSize);
	int val = 0;
	
	while (f >> val) {
		int arrPos = val / bitElementSize;
		int bitPos = val % bitElementSize;

		setBit(&bitVector[arrPos], bitPos);
	}

	// do the processing
	for (size_t arrPos = 0; arrPos < bitVector.size(); ++arrPos) {
		for (size_t bitPos = 0; bitPos < bitElementSize; ++bitPos) {
			int bit = getBit(bitVector[arrPos], bitPos);

			if (bit == 0) {
				return arrPos*bitElementSize + bitPos;
			}
		}
	}

	return -1;
}

int sparseSearch(const std::vector<std::string>& arr, const std::string& val) {
	int startIndex = 0;
	int endIndex = arr.size() - 1;

	while (startIndex < endIndex) {
		int mid = (startIndex + endIndex) / 2;

		if (arr[mid] == "") {
			while (mid > startIndex) {
				if (arr[--mid] != "")
					break;
			}
		}

		if (val < arr[mid])
			endIndex = mid - 1;
		else if (val > arr[mid])
			startIndex = mid + 1;
		else
			return mid;


	}

	return -1;
}