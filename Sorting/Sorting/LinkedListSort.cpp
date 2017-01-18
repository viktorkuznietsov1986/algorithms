#include "LinkedListSort.h"


void LinkedListSort::sort(std::list<std::string>& lst) {
	auto hi = lst.end();
	--hi;
	sort(lst, lst.begin(), hi, 0);
}

void LinkedListSort::sort(std::list<std::string>& lst, list_iterator& lo, list_iterator& hi, int w) {
	if (lo == hi)
		return;

	

	auto lt = lo;
	auto v = getChar(lt, w);
	auto i = lt;
	++i;

	/*if (i == hi)
		return;*/

	auto gt = hi;

	while (i != lst.end()) {
		bool stop = (i == gt);

		if (getChar(lt, w) > getChar(i, w)) {
			std::iter_swap(lt++, i++);
		}
		else if (getChar(lt, w) < getChar(i, w)) {
			std::iter_swap(i, gt--);
		}
		else {
			++i;
		}

		if (stop)
			break;
	}

	auto hiBound = lt;
	if (getChar(hiBound, w) != getChar(lst.begin(), w) && lt != lo) --hiBound;
	sort(lst, lo, hiBound, w);
	
	if (v >= 0) sort(lst, lt, gt, w + 1);
	
	if (getChar(gt, w) == getChar(lt, w) && gt != hi) ++gt;
	sort(lst, gt, hi, w);

}

int LinkedListSort::getChar(list_iterator& it, int w) {
	if (it->size() <= w)
		return -1;

	return (*it)[w];
}
