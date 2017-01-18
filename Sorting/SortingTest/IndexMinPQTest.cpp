#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "IndexMinPQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(IndexMinPQTest)
	{
	private:
		template <typename T>
		static bool isSorted(std::vector<T>& a) {
			bool sorted = true;
			for (size_t i = 0; i < a.size() - 1; ++i) {
				if (a[i] > a[i + 1]) {
					sorted = false;
					break;
				}
			}

			return sorted;
		}

	public:

		TEST_METHOD(IndexMaxPQ_BasicFlowTest)
		{
			std::vector<int> arr1;
			arr1.push_back(3);
			arr1.push_back(2);
			arr1.push_back(1);

			std::vector<int> arr2;
			arr2.push_back(3);
			arr2.push_back(3);
			arr2.push_back(1);
			arr2.push_back(1);


			std::vector<int> arr3;
			arr3.push_back(1);
			arr3.push_back(0);

			std::vector<std::vector<int> > arr;
			arr.push_back(arr1);
			arr.push_back(arr2);
			arr.push_back(arr3);

			IndexMinPQ<int> pq;

			for (int i = 0; i < 3; ++i) {
				if (arr[i].size()) {
					pq.insert(i, arr[i][0]);
					arr[i].erase(arr[i].begin());
				}
			}

			std::vector<int> resultingArr;

			while (!pq.isEmpty()) {
				resultingArr.push_back(pq.minKey());
				int i = pq.delMin();

				if (arr[i].size()) {
					pq.insert(i, arr[i][0]);
					arr[i].erase(arr[i].begin());
				}
			}

			Assert::IsTrue(isSorted(resultingArr));
		}


	};
}

#endif
