#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "MergeSort.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(MergeSortTest)
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

		TEST_METHOD(TopDownMergeSort_InsertionSortBasicFlowTest)
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
			CMergeSort<int>::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(TopDownMergeSort_ImprovedBasicFlowTest)
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
			CMergeSort<int>::sortTD(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(TopDownMergeSort_ComplexBasicFlowTest)
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
			CMergeSort<int>::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(TopDownMergeSort_ImprovedComplexBasicFlowTest)
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
			CMergeSort<int>::sortTD(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(BottomUpMergeSort_BasicFlowTest)
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
			CMergeSort<int>::sortBU(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(BottomUpQueuedMergeSort_BasicFlowTest)
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
			CMergeSort<int>::sortBUQ(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(TopDownMergeSort3_BasicFlowTest)
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
			CMergeSort<int>::sort3(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(TopDownMergeSort3_ImprovedComplexBasicFlowTest)
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
			CMergeSort<int>::sort3(arr);

			Assert::IsTrue(isSorted(arr));

		}


	};
}

#endif
