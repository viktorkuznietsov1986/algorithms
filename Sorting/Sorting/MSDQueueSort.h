#pragma once
#include <vector>
#include <string>
#include <queue>

class MSDQueueSort
{
public:
	static void sort(std::vector<std::string>& arr);

private:
	static void sort(std::queue<std::string>& q, int w);

	static int getChar(const std::string& str, int w) {
		if (w >= str.size()) {
			return -1;
		}

		return static_cast<int>(str[w]);
	}
};

