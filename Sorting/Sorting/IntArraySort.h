#pragma once

#include <vector>

class IntArraySort
{
public:
	static void sort(std::vector<std::vector<int>>& a);

private:
	static void sort(std::vector<std::vector<int>>& a, int lo, int hi, int w);
	static int getValue(const std::vector<int>&a, int pos);
};

