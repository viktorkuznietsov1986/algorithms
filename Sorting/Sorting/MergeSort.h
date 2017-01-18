#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <queue>
#include <list>
#include "InsertionSort.h"

const int SMALL_ARRAY_SIZE = 15;

template <typename T>
class CMergeSort
{

public:
	static void sort(std::vector<T>& a) {
		auto sorter = std::unique_ptr<CMergeSort<T>>(new CMergeSort<T>(a));
		sorter->sort_topdown(a, 0, a.size() - 1);
	}

	static void sort3(std::vector<T>& a) {
		auto sorter = std::unique_ptr<CMergeSort<T>>(new CMergeSort<T>(a));
		sorter->sort_topdown3(a, 0, a.size() - 1);
	}

	static void sortTD(std::vector<T>& a) {
		auto sorter = std::unique_ptr<CMergeSort<T>>(new CMergeSort<T>(a.size()));
		sorter->sort_topdown1(a, 0, a.size() - 1, true);
	}

	static void sortBU(std::vector<T>& a) {
		auto sorter = std::unique_ptr<CMergeSort<T>>(new CMergeSort<T>(a));
		sorter->sort_bottomup(a);
	}

	static void sortBUQ(std::vector<T>& a) {
		if (a.size() > 0) {
			std::queue<std::shared_ptr<std::queue<T> > > q;
			for (size_t i = 0; i < a.size(); ++i) {
				auto pq = std::shared_ptr<std::queue<T> >(new std::queue<T>());
				pq->push(a[i]);
				q.push(pq);
			}

			while (q.size() > 1) {
				auto pq1 = q.front();
				q.pop();
				auto pq2 = q.front();
				q.pop();
				q.push(merge_sorted_queues(pq1, pq2));
			}


			auto resQueue = q.front();
			for (size_t i = 0; i < a.size(); ++i) {
				a[i] = resQueue->front();
				resQueue->pop();
			}
		}
	}



private:
	CMergeSort(const std::vector<T>& a) {
		aux = std::vector<T>(a);
	}

	CMergeSort(int size) {
		aux = std::vector<T>();
		aux.resize(size);
	}

	CMergeSort(const CMergeSort&) = delete;
	CMergeSort(CMergeSort&&) = delete;
	CMergeSort& operator=(const CMergeSort&) = delete;

	static std::shared_ptr<std::queue<T> > merge_sorted_queues(std::shared_ptr<std::queue<T> > q1,
		std::shared_ptr<std::queue<T> > q2) {

		auto result = std::shared_ptr<std::queue<T> >(new std::queue<T>());

		while (true) {
			if (q1->empty() && q2->empty()) {
				break;
			}

			if (q1->empty() && !q2->empty()) {
				result->push(q2->front());
				q2->pop();
			} 
			else if (q2->empty() && !q1->empty()) {
				result->push(q1->front());
				q1->pop();
			}
			else if (q1->front() > q2->front()) {
				result->push(q2->front());
				q2->pop();
			}
			else {
				result->push(q1->front());
				q1->pop();
			}
		}

		return result;
	}

	void sort_topdown3(std::vector<T>& a, int lo, int hi) {
		if (hi <= lo)
			return;

		int m1 = lo + (hi - lo) / 3;
		int m2 = lo + 2 * (hi - lo) / 3;

		sort_topdown3(a, lo, m1);
		sort_topdown3(a, m1 + 1, m2);
		sort_topdown3(a, m2 + 1, hi);

		merge3(a, lo, m1, m2, hi);
	}

	void merge3(std::vector<T>& a, int lo, int m1, int m2, int hi) {
		std::copy(a.begin() + lo, a.begin() + hi + 1, aux.begin() + lo);

		int i = lo;
		int j = m1 + 1;
		int k = m2 + 1;

		for (int l = lo; l <= hi; ++l) {
			
			if (i > m1) {
				if (j > m2) {
					a[l] = aux[k++];
				}
				else if (k > hi) {
					a[l] = aux[j++];
				}
				else if (aux[j] > aux[k])
					a[l] = aux[k++];
				else
					a[l] = aux[j++];
			}
			else if (j > m2) {
				if (i > m1) {
					a[l] = aux[k++];
				}
				else if (k > hi) {
					a[l] = aux[i++];
				}
				else if (aux[i] > aux[k])
					a[l] = aux[k++];
				else
					a[l] = aux[i++];
			}
			else if (k > hi) {
				if (j > m2) {
					a[l] = aux[i++];
				}
				else if (i > m1) {
					a[l] = aux[j++];
				}
				else if (aux[j] > aux[i])
					a[l] = aux[i++];
				else
					a[l] = aux[j++];
			}
			else if (aux[i] <= aux[j] && aux[i] <= aux[k]) {
				a[l] = aux[i++];
			} 
			else  if (aux[j] <= aux[i] && aux[j] <= aux[k]) {
				a[l] = aux[j++];
			}
			else if (aux[k] <= aux[i] && aux[k] <= aux[j]) {
				a[l] = aux[k++];
			}
		}
	}

	void sort_topdown(std::vector<T>& a, int lo, int hi) {
		if (hi <= lo)
			return;

		int arrSize = hi - lo;
		if (SMALL_ARRAY_SIZE >= arrSize) {
			InsertionSort::sort(a, lo, hi);
		}
		else {
			int mid = lo + (hi - lo) / 2;
			sort_topdown(a, lo, mid);
			sort_topdown(a, mid + 1, hi);

			// don't do the merge if the last value of the first array is smaller than the first value of the second; in this case the array is already in proper order
			if (a[mid] > a[mid + 1]) {
				merge(a, lo, mid, hi);
			}
		}
	}

	// tricky sort method which allows to save time on copying the aux array
	bool sort_topdown1(std::vector<T>& a, int lo, int hi, bool useAux) {
		if (hi <= lo)
			return !useAux;

		int arrSize = hi - lo;
		
		if (SMALL_ARRAY_SIZE >= arrSize) {
			// use InsertionSort for small arrays
			InsertionSort::sort(a, lo, hi);
		}
		else {

			int mid = lo + (hi - lo) / 2;

			sort_topdown1(a, lo, mid, useAux);
			sort_topdown1(a, mid + 1, hi, useAux);

			if (a[mid] > a[mid + 1]) {
				// don't do the merge if the last value of the first array is smaller than the first value of the second; in this case the array is already in proper order
				merge1(a, lo, mid, hi, !useAux);
			}
		}

		return !useAux;
		
	}

	void merge1(std::vector<T>& a, int lo, int mid, int hi, bool useAux) {

		if (useAux) {
			merge2(aux, a, lo, mid, hi);
		}
		else {
			merge2(a, aux, lo, mid, hi);
		}
		
	}

	void merge2(std::vector<T>&a1, std::vector<T>&a2, int lo, int mid, int hi) {
		int i = lo, j = mid + 1;
		// copy a[lo..hi] to aux
		for (int k = lo; k <= hi; ++k)
			a2[k] = a1[k];

		// merge back to a[lo..hi]
		for (int k = lo; k <= hi; ++k) {
			if (i > mid)
				a1[k] = a2[j++];
			else if (j > hi)
				a1[k] = a2[i++];
			else if (less(a2[j], a2[i]))
				a1[k] = a2[j++];
			else
				a1[k] = a2[i++];
		}
	}

	void sort_bottomup(std::vector<T>& a) {
		int N = a.size();
		for (int sz = 1; sz < N; sz = sz + sz) {
			for (int lo = 0; lo < N - sz; lo += sz + sz) {
				merge(a, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));
			}
		}
	}

	void merge(std::vector<T>& a, int lo, int mid, int hi) {
		int i = lo, j = mid + 1;

		// copy a[lo..hi] to aux
		for (int k = lo; k <= hi; ++k) 
			aux[k] = a[k];

		// merge back to a[lo..hi]
		for (int k = lo; k <= hi; ++k) {
			if (i > mid)
				a[k] = aux[j++];
			else if (j > hi)
				a[k] = aux[i++];
			else if (less(aux[j], aux[i]))
				a[k] = aux[j++];
			else
				a[k] = aux[i++];
		}
	}

	bool less(const T& l, const T& r) {
		return l < r;
	}

	std::vector<T> aux;
};

