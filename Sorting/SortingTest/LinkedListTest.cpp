#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "List.h"

#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	
	TEST_CLASS(LinkedList_Test)
	{
	public:

		TEST_METHOD(LinkedList_SortedPositiveTest)
		{
			List<int> list;

			list.AddLast(1);
			list.AddLast(2);
			list.AddLast(3);
			
			Assert::IsTrue(list.isSorted());
		}

		TEST_METHOD(LinkedList_SortedNegativeTest)
		{
			List<int> list;

			list.AddLast(2);
			list.AddLast(1);
			list.AddLast(3);

			Assert::IsFalse(list.isSorted());
		}

		TEST_METHOD(LinkedList_MergeSortTest) {
			const int iterations = 1000;
			int min = 0;
			int max = 1000;
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uni(min, max);
			List<int> list;
			for (int i = 0; i < iterations; ++i) {
				list.AddLast(uni(rng));
			}

			list.Sort();

			Assert::IsTrue(list.isSorted());
		}

	};
}

#endif
