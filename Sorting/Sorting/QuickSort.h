#pragma once
#include <vector>
#include <algorithm>
#include "InsertionSort.h"

const int SIZE_TO_USE_INSERTION_SORT = 10;

template <typename T>
class CQuickSort
{
public:
	static void sort(std::vector<T>& a) {
		std::random_shuffle(a.begin(), a.end());
		int N = a.size() - 1;
		sort(a, 0, N);
	}

	static void sort3(std::vector<T>& a) {
		std::random_shuffle(a.begin(), a.end());
		int N = a.size() - 1;
		sort3(a, 0, N);
	}

	static void sort2distinct(std::vector<T>& a) {
		int lo = 0, hi = a.size() - 1;;
		sort2distinct(a, 0, a.size() - 1);
	}

	

private:
	CQuickSort() = delete;

	static void sort2distinct(std::vector<T>& a, int lo, int hi) {
		if (hi <= lo)
			return;

		int i = lo, j = hi + 1;
		T v = a[lo];
		while (true) {
			while (a[++i] == v) {
				if (i == hi)
					break;
			}

			while (a[--j] != v) {
				if (j == lo)
					break;
			}

			if (i >= j)
				break;

			std::iter_swap(a.begin() + j, a.begin() + i);
		}

		if (a[lo] > a[hi])
			std::reverse(a.begin() + lo, a.begin() + hi+1);
	}

	static void sort3(std::vector<T>& a, int lo, int hi) {
		if (hi <= lo)
			return;

		if (hi <= lo + SIZE_TO_USE_INSERTION_SORT) {
			InsertionSort::sort(a, lo, hi);
		}
		else {
			int lt = lo, i = lo + 1, gt = hi;

			T v = a[lo];
			while (i <= gt) {
				
				if (a[i] < v) {
					std::iter_swap(a.begin() + i++, a.begin() + lt++);
				}
				else if (a[i] > v) {
					std::iter_swap(a.begin() + i, a.begin() + gt--);
				}
				else {
					++i;
				}
			}

			sort(a, lo, lt);
			sort(a, gt, hi);
		}
	}

	static void sort(std::vector<T>& a, int lo, int hi) {
		if (hi <= lo)
			return;

		if (hi <= lo + SIZE_TO_USE_INSERTION_SORT) {
			InsertionSort::sort(a, lo, hi);
		}
		else {
			int j = partition(a, lo, hi);
			sort(a, lo, j - 1);
			sort(a, j + 1, hi);
		}
	}

	static int partition(std::vector<T>& a, int lo, int hi) {
		int i = lo, j = hi + 1;
		T v = a[lo];

		while (true) {
			while (a[++i] < v) {
				if (i == hi) {
					break;
				}
			}

			while (a[--j] > v) {
				if (j == lo) {
					break;
				}
			}

			if (i >= j)
				break;

			std::iter_swap(a.begin() + i, a.begin() + j);
			
		}

		std::iter_swap(a.begin() + lo, a.begin() + j);
		return j;
	}
	
};

