#include "IntArraySort.h"

#include <algorithm>
#include <climits>


void IntArraySort::sort(std::vector<std::vector<int>>& a) {
	sort(a, 0, a.size() - 1, 0);
}

void IntArraySort::sort(std::vector<std::vector<int>>& a, int lo, int hi, int w) {
	if (lo + 1 >= hi)
		return;

	auto lt = lo;
	auto i = lt + 1;
	auto v = getValue(a[lo], w);
	auto gt = hi;

	while (i <= gt) {
		if (getValue(a[lt], w) > getValue(a[i], w)) std::iter_swap(a.begin() + lt++, a.begin() + i++);
		else if (getValue(a[lt], w) < getValue(a[i], w)) std::iter_swap(a.begin() + i, a.begin() + gt--);
		else ++i;
	}

	sort(a, lo, lt - 1, w);
	sort(a, lt, gt, w + 1);
	sort(a, gt + 1, hi, w);
}

int IntArraySort::getValue(const std::vector<int>&a, int pos) {
	if (pos >= a.size())
		return INT_MIN;

	return a[pos];
}
