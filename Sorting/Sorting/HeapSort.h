#pragma once
#include <vector>
#include <algorithm>

template <typename T>
class CHeapSort
{
public:
	static void sort(std::vector<T>& a) {
		int N = a.size();
		for (int i = N/2; i >= 1; i--) {
			sink(a, i, N);
		}

		while (N > 1) {
			exch(a, 1, N--);
			sink(a, 1, N);
		}
	}

private:
	static void sink(std::vector<T>& a, int start, int end) {
		int i = start;
		
		while (i*2 < end) {
			int j = i * 2;

			if (j < end && less(a, j, j+1))
				++j;

			if (!less(a, i, j))
				break;

			exch(a, i, j);
			i = j;
		}
	}

	static bool less(std::vector<T>& a, int i, int j) {
		return a[i-1] < a[j-1];
	}

	static void exch(std::vector<T>& a, int i, int j) {
		std::iter_swap(a.begin() + i - 1, a.begin() + j - 1);
	}
};

