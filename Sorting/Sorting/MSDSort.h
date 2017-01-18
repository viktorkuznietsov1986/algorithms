#pragma once
#include <vector>
#include <string>

class MSDSort
{
private:
	static void sort(std::vector<std::string>& arr, int lo, int hi, int w);

public:
	static void sort(std::vector<std::string>& arr);
};

