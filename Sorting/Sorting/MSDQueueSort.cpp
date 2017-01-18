#include "MSDQueueSort.h"
#include "InsertionSort.h"

#include <queue>
#include <map>
#include <string>

const int alphabetSize = 256;
const int maxInsertionSort = 15;


void MSDQueueSort::sort(std::vector<std::string>& arr) {
	
	/*if (hi - lo <= maxInsertionSort) {
		InsertionSort::sort(arr, lo, hi, w);
		return;
	}*/

	std::map<int, std::queue<std::string>> items;
	int w = 0;

	for (int i = 0; i < arr.size(); ++i) {
		auto c = getChar(arr[i], w);
		auto bin = items.find(c);

		if (bin == items.end()) {
			std::queue<std::string> b;
			b.push(arr[i]);
			items.emplace(c, b);
		}
		else {
			bin->second.push(arr[i]);
		}
	}

	for (auto bin = items.begin(); bin != items.end(); ++bin) {
		if (bin->second.size() > 1) {
			sort(bin->second, w+1);
		}
	}

	auto idx = 0;
	for (auto bin = items.begin(); bin != items.end(); ++bin) {
		auto q = &(bin->second);
		while (q->size()) {
			arr[idx++] = q->front();
			q->pop();
		}
	}


}

void MSDQueueSort::sort(std::queue<std::string>& q, int w) {
	std::map<int, std::queue<std::string>> items;

	while (q.size()) {
		auto str = q.front();
		q.pop();
		auto c = getChar(str, w);
		auto bin = items.find(c);

		if (bin == items.end()) {
			std::queue<std::string> b;
			b.push(str);
			items.emplace(c, b);
		}
		else {
			bin->second.push(str);
		}
	}

	for (auto bin = items.begin(); bin != items.end(); ++bin) {
		if (bin->second.size() > 1) {
			sort(bin->second, w + 1);
		}
	}

	auto idx = 0;
	for (auto bin = items.begin(); bin != items.end(); ++bin) {
		auto b = &(bin->second);
		while (b->size()) {
			q.push(b->front());
			b->pop();
		}
	}
}
