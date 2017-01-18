#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "IntArraySort.h"

#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(IntArraySortTest)
	{
	public:

		TEST_METHOD(IntArraySort_BasicFlowTest)
		{
			
			std::vector<int> a1{5, 1, 3};
			std::vector<int> a2{1, 1};
			std::vector<int> a3{ 9, 1, 3, 6 };
			std::vector<int> a4{ 9, 1, 3 };
			std::vector<int> a5{ 4, 5, 3 };
			std::vector<int> a6{ 5, 1, 2 };
			std::vector<std::vector<int>> arr{a1,a2,a3,a4,a5,a6};

			IntArraySort::sort(arr);

			std::vector<std::vector<int>> result{ a2,a5,a6,a1,a4,a3 };

			Assert::IsTrue(std::equal(arr.begin(), arr.end(), result.begin(), result.end()));
		}


	};
}

#endif
