#pragma once

#include <string>
#include <vector>

void lastKLines(const char* fileName, int k);

void reverse(char* str);

int** my2DAlloc(int rows, int columns);

void myDeAlloc(int** arr, int rows);

int tripleStep(int n);

int tripleStepRec(int n, int* arr);

int missingInt(const char* fileName);

int sparseSearch(const std::vector<std::string>& arr, const std::string& val);
