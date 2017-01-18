#include "arrays.h"

#include <cstring>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <string>

#include <queue>
#include <memory>

bool isStringWithUniqueCharacters(const char* str) {
	assert(str != nullptr);
	
	//the following solution will take O(N*log(N))
	/*size_t len = strlen(str);
	auto buff = new char[len + 1];

	strcpy_s(buff, len+1, str);

	std::sort(buff, buff + len - 1);

	bool isUnique = true;
	for (size_t i = 1; i < len; ++i) {
		if (buff[i] == buff[i - 1]) {
			isUnique = false;
			break;
		}
	}

	delete [] buff;
	return isUnique*/;

	// the solution will take O(N)
	auto asciiTable = new bool[128]; // introducing the ascii table to be used for the characters.

	// this need to be initialized to be sure that it works properly
	for (int i = 0; i < 128; ++i)
		asciiTable[i] = false;

	size_t len = strlen(str);

	bool result = true;

	for (size_t i = 0; i < len; ++i) {
		if (asciiTable[str[i]]) {
			result = false;
			break;
		}

		asciiTable[str[i]] = true;
	}

	delete[] asciiTable;

	return result;
}

bool isPermutation(const char* str1, const char* str2) {
	assert(str1 != nullptr);
	assert(str2 != nullptr);

	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);

	if (len1 != len2)
		return false;

	// this implementation has O(N*log(N)) runtime.
	/*auto buff1 = new char[len1 + 1];
	strcpy_s(buff1, len1 + 1, str1);
	std::sort(buff1, buff1 + len1 - 1);

	auto buff2 = new char[len2 + 1];
	strcpy_s(buff2, len2 + 1, str2);
	std::sort(buff2, buff2 + len2 - 1);

	bool isPerm = true;
	for (size_t i = 0; i < len1; ++i) {
		if (buff1[i] != buff2[i]) {
			isPerm = false;
			break;
		}
	}

	delete[] buff1;
	delete[] buff2;*/

	// this will use O(N).
	auto asciiSymbolTable = new int[127];

	for (size_t i = 0; i < 127; ++i)
		asciiSymbolTable[i] = 0;

	for (size_t i = 0; i < len1; ++i) {
		++asciiSymbolTable[str1[i]];
	}

	bool isPerm = true;

	for (size_t i = 0; i < len1; ++i) {
		--asciiSymbolTable[str2[i]];

		if (asciiSymbolTable[str2[i]] < 0) {
			isPerm = false;
			break;
		}
	}

	delete[] asciiSymbolTable;

	return isPerm;



}



int magicIndex(const std::vector<int>& arr, int startIndex, int endIndex) {
	if (startIndex > endIndex)
		return -1;

	int midIndex = (startIndex + endIndex) / 2;

	if (arr[midIndex] == midIndex)
		return midIndex;
	else if (arr[midIndex] < midIndex) {
		return magicIndex(arr, midIndex + 1, endIndex);
	}
	else
		return magicIndex(arr, 0, midIndex-1);

}

void mergeTwoSortedArrays(std::vector<int>& a, int elementsCount, std::vector<int>& b) {
	int indexToCopyFromA = elementsCount - 1;
	int indexToCopyFromB = b.size() - 1;
	int indexA = a.size() - 1;

	while (indexToCopyFromA >= 0 && indexToCopyFromB >= 0) {
		if (a[indexToCopyFromA] < b[indexToCopyFromB]) {
			a[indexA] = b[indexToCopyFromB];
			--indexToCopyFromB;
		}
		else {
			a[indexA] = a[indexToCopyFromA];
			--indexToCopyFromA;
		}

		--indexA;
	}
}

void makeZeroRow(int**a, int n, int row) {
	if (a) {
		for (int i = 0; i < n; ++i) {
			a[row][i] = 0;
		}
	}
}

void makeZeroColumn(int** a, int m, int col) {
	if (a) {
		for (int i = 0; i < m; ++i) {
			a[i][col] = 0;
		}
	}
}

void zeroMatrix(int** a, int m, int n) {
	if (a) {
		bool rowHasZero = false;
		bool colHasZero = false;

		for (int i = 0; i < m; ++i) {
			if (a[i][0] == 0) {
				rowHasZero = true;
				break;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (a[0][i] == 0) {
				colHasZero = true;
				break;
			}
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < m; ++j) {
				if (a[i][j] == 0) {
					a[i][0] = 0;
					a[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i) {
			if (a[i][0] == 0)
				makeZeroRow(a, m, i);
		}

		for (int i = 1; i < n; ++i) {
			if (a[0][i] == 0)
				makeZeroColumn(a, n, i);
		}

		if (rowHasZero) {
			makeZeroRow(a, m, 0);
		}

		if (colHasZero) {
			makeZeroColumn(a, n, 0);
		}

	}
}

int sumOfMostCommonIntRuntime(const std::vector<int>& a) {
	// runtime: O(a.size())
	// space: O(a.size() + cashed_integers.size())
	if (a.size() == 0)
		return -1;

	std::unordered_map<int, int> cashed_integers;
	int value = 0;
	int count = -1;

	for (int i = 0; i < a.size(); ++i) {
		auto integer = a[i];
		if (cashed_integers.find(integer) != cashed_integers.end()) {
			++cashed_integers[integer];
		}
		else {
			cashed_integers[integer] = 1;
		}

		if (cashed_integers[integer] > count) {
			count = cashed_integers[integer];
			value = integer;
		}
	}

	return value*count;
}

int sumOfMostCommonIntSpace(std::vector<int>& a) {
	// runtime: O(n*log(n)), where n - a.size()
	// space: O(a.size())
	if (a.size() == 0)
		return -1;

	std::sort(a.begin(), a.end()); // the best would be to use the quick sort, so the array is sorted in place.

	int value = a[0];
	int count = 1;

	int curr_value = a[0];
	int curr_count = 1;

	for (int i = 1; i < a.size(); ++i) {
		auto integer = a[i];
		
		if (curr_value == integer) {
			++curr_count;
		}
		else {
			if (curr_count > count) {
				count = curr_count;
				value = curr_value;
				
				curr_value = integer;
				curr_count = 1;
			}
		}

	}

	return value*count;
}

bool isMoreOrEqual60Percent(int count, int size) {
	auto percentage = static_cast<double>(count) * 100.0 / static_cast<double>(size);
	return percentage >= 60.0;
}

// finds the integer which occurs more than 60%
// returns -1 if no proper result
int findMostCommonPositiveInteger(const std::vector<int>& a) {
	if (a.size() == 0)
		return -1;

	std::unordered_map<int, int> cache;
	int integer = -1;
	int count = -1;
	
	for (size_t i = 0; i < a.size(); ++i) {
		auto value = a[i];

		if (value < 0) {
			return -1;
		}

		if (cache.find(value) == cache.end()) {
			cache[value] = 1;
		}
		else {
			++cache[value];
		}

		if (cache[value] > count) {
			count = cache[value];
			integer = value;
		}

		if (isMoreOrEqual60Percent(count, a.size()))
			break;
	}

	if (!isMoreOrEqual60Percent(count, a.size()))
		return -1;

	return integer;
}

int maxProfitMultipleTrades(const std::vector<int>& a) {
	if (a.size() == 0)
		return 0;

	int profit = 0;

	int buy = a[0];
	int sell = a[0];

	for (size_t i = 1; i < a.size(); ++i) {
		
		if (a[i] <= 0)
			return 0;

		if (sell > a[i]) {
			profit += sell - buy;
			buy = sell = a[i];
		}
		else {
			sell = a[i];
		}
	}

	profit += sell - buy;

	return profit;
}

int maxProfitSingleTrade(const std::vector<int>& a) {
	if (a.size() == 0)
		return 0;

	int profit = 0;

	int buy = a[0];
	int sell = a[0];

	for (size_t i = 1; i < a.size(); ++i) {

		if (a[i] <= 0)
			return 0;

		if (sell > a[i]) {
			if (profit < sell - buy)
				profit = sell - buy;
			
			buy = sell = a[i];
		}
		else {
			sell = a[i];
		}
	}

	if (profit < sell - buy)
		profit = sell - buy;

	return profit;
}

int maxProfitTwoTrades(const std::vector<int>& a) {
	// todo implement

	if (a.size() == 0)
		return 0;

	int profit1 = 0;
	int profit2 = 0;

	int buy = a[0];
	int sell = a[0];

	for (size_t i = 1; i < a.size(); ++i) {

		if (a[i] <= 0)
			return 0;

		if (sell > a[i]) {
			if (profit1 < sell - buy) {
				profit2 = profit1;
				profit1 = sell - buy;
			}
			else if (profit2 < sell - buy) {
				profit2 = sell - buy;
			}

			buy = sell = a[i];
		}
		else {
			sell = a[i];
		}
	}

	if (profit1 < sell - buy) {
		profit2 = profit1;
		profit1 = sell - buy;
	}
	else if (profit2 < sell - buy) {
		profit2 = sell - buy;
	}

	return profit1 + profit2;
}

static int updateStringWithTheNumber(char* str, int pos, int number) {
	assert(str != nullptr);
	assert(pos >= 0 && pos < strlen(str));

	auto nbr = std::to_string(number);
	for (size_t c = 0; c < nbr.size(); ++c)
		str[pos++] = nbr[c];

	return pos;
}

// encodes the input string by adding numbers for the symbols occurrences
// example: AABBBCCCC will be as 2A3B4C
// returns a pointer to a newly intialized memory
// call free() to clean it up
char* encode(const char* str) {
	if (str == nullptr)
		return nullptr;

	const auto streamLength = strlen(str);

	if (streamLength == 0) {
		return nullptr;
	}

	std::string result;

	auto q = std::make_unique<std::queue<char>>();
	char prev = str[0];
	q->emplace(prev);
	auto i = 1;
	int sameCnt = 1;

	while (q->size() && i < streamLength) {
		auto curr = str[i];

		if (curr != prev) {
			if (sameCnt > 1) {
				result += std::to_string(sameCnt) + q->front();
				q->pop();
				sameCnt = 1;
			}

			q->emplace(curr);
			prev = curr;
		}
		else {
			++sameCnt;

			if (q->size() > 1) {
				auto size = q->size() - 1;
				result += "0" + std::to_string(size);
				while (q->size() > 1) {
					result += q->front();
					q->pop();
				}
			}
		}

		++i;
	}

	if (q->size() > 1) {
		auto size = q->size();
		result += "0" + std::to_string(size);
		while (q->size()) {
			result += q->front();
			q->pop();
		}
	}
	else {
		if (sameCnt > 1) {
			result += std::to_string(sameCnt) + q->front();
			q->pop();
		}
		else {
			result += "01";
			result += q->front();
			q->pop();
		}
	}

	auto buffer = static_cast<char*>(malloc(sizeof(char)*(result.size() + 1)));
	strcpy_s(buffer, result.size()+1, result.c_str());

	return buffer;
}

// decodes the input string encoded by method encode
// example: 2A3B4C will be as AABBBCCCC 
// returns a pointer to a newly intialized memory
// call free() to clean it up
char* decode(const char* str) {
	if (str == nullptr)
		return nullptr;
	
	int bufferSize = strlen(str);

	if (bufferSize == 0)
		return nullptr;

	std::string result;
	auto i = 0;

	while (i < bufferSize) {
		auto m = str[i++];

		bool isUniqueStr = false;
		
		if (m == '0') {
			isUniqueStr = true;
			m = str[i++];
		}

		int cnt = m - '0';

		if (isUniqueStr) {
			for (size_t c = i; c < i + cnt; ++c) {
				result += str[c];
			}
			
		}
		else {
			for (size_t c = 0; c < cnt; ++c) {
				result += str[i];
			}

			cnt = 1;
		}

		i += cnt;
	}

	auto buffer = static_cast<char*>(malloc(sizeof(char)*(result.size() + 1)));
	strcpy_s(buffer, result.size() + 1, result.c_str());

	return buffer;
}