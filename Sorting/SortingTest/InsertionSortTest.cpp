#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "InsertionSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(InsertionSortTest)
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

		TEST_METHOD(InsertionSort_BasicFlowTest)
		{
			std::vector<int> arr;
			arr.push_back(0);
			arr.push_back(10);
			arr.push_back(5);
			arr.push_back(25);
			arr.push_back(4);
			arr.push_back(14);
			arr.push_back(15);
			arr.push_back(1);
			InsertionSort::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}


	};
}

#endif
