#pragma once

#include <vector>

bool isStringWithUniqueCharacters(const char* str);
bool isPermutation(const char* str1, const char* str2);

int magicIndex(const std::vector<int>& arr, int startIndex, int endIndex);

void mergeTwoSortedArrays(std::vector<int>& a, int elementsCount, std::vector<int>& b);

void zeroMatrix(int** a, int m, int n);

int sumOfMostCommonIntRuntime(const std::vector<int>& a);
int sumOfMostCommonIntSpace(std::vector<int>& a);

// finds the integer which occurs more than 60%
int findMostCommonPositiveInteger(const std::vector<int>& a);

int maxProfitMultipleTrades(const std::vector<int>& a);
int maxProfitSingleTrade(const std::vector<int>& a);
int maxProfitTwoTrades(const std::vector<int>& a);

// encodes the input string by adding numbers for the symbols occurrences
// example: AABBBCCCC will be as 2A3B4C
char* encode(const char* str);
char* decode(const char* str);


