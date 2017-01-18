#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "QuickSort.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(QuickSortTest)
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

		TEST_METHOD(QuickSort_BasicFlowTest)
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
			CQuickSort<int>::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(QuickSort_ComplexBasicFlowTest)
		{
			const int iterations = 1000;
			std::vector<int> arr;
			int min = 0;
			int max = 1000;
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uni(min, max);
			for (int i = 0; i < iterations; ++i) {
				arr.push_back(uni(rng));
			}
			CQuickSort<int>::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(QuickSort3_BasicFlowTest)
		{
			std::vector<int> arr;
			arr.push_back(0);
			arr.push_back(4);
			arr.push_back(5);
			arr.push_back(25);
			arr.push_back(4);
			arr.push_back(14);
			arr.push_back(4);
			arr.push_back(1);
			CQuickSort<int>::sort3(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(QuickSort3_ComplexBasicFlowTest)
		{
			const int iterations = 1000;
			std::vector<int> arr;
			int min = 0;
			int max = 1000;
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uni(min, max);
			for (int i = 0; i < iterations; ++i) {
				arr.push_back(uni(rng));
			}
			CQuickSort<int>::sort3(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(QuickSort2Distinct_ComplexBasicFlowTest)
		{
			const int iterations = 10000;
			std::vector<int> arr;
			int min = 0;
			int max = 1;
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uni(min, max);
			for (int i = 0; i < iterations; ++i) {
				arr.push_back(uni(rng));
			}
			CQuickSort<int>::sort2distinct(arr);

			Assert::IsTrue(isSorted(arr));
		}

		


	};
}

#endif
