#pragma once
#include <vector>
#include <cassert>

class InsertionSort
{
public:
	template <typename T>
	static void sort(std::vector<T>& a) {
		assert(a.size() > 0);
		int N = a.size();
		sort(a, 0, N - 1);
	}

	template <typename T>
	static void sort(std::vector<T>& a, int lo, int hi) {
		assert(lo < hi);

		for (int i = lo; i <= hi; ++i) {
			for (int k = i; k > lo; --k) {
				if (a[k] > a[k-1])
					break;
				
				std::iter_swap(a.begin() + k, a.begin() + k - 1);
			}
		}
	}

	static void sort(std::vector<std::string>& a, int lo, int hi, int w) {
		assert(lo < hi);

		for (int i = lo+1; i <= hi; ++i) {
			for (int k = i; k > lo; --k) {
				if (getChar(a[k], w) > getChar(a[k-1], w))
					break;

				std::iter_swap(a.begin() + k, a.begin() + k - 1);
			}
		}

		auto start = lo;
		auto symbol = getChar(a[start++], w);
		auto cnt = 1;

		while (start <= hi) {

			auto s = getChar(a[start++], w);

			if (s == symbol) {
				++cnt;
			}
			else {
				if (cnt > 1)
					sort(a, start-cnt-1, start - 2, w + 1);

				symbol = s;
				cnt = 1;
			}
		}

		if (cnt > 1)
			sort(a, start - cnt - 1, start - 2, w + 1);
	}

private:
	static int getChar(const std::string& str, int w) {
		if (w >= str.size()) {
			return -1;
		}
		
		return static_cast<int>(str[w]);
	}
};

