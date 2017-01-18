#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "SublinearSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(SublinearSortTest)
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

		TEST_METHOD(SublinearSort_BasicFlowTest)
		{
			std::vector<int> arr{999999, 888888, 777777, 1, 100008888, 0, 16, 12, 5, 8, 75000};
			SublinearSort::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}


	};
}

#endif
