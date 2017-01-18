#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryHeapMaxPQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(BinaryHeapMaxPQTest)
	{
	public:

		TEST_METHOD(BinaryHeapMaxPQ_BasicFlowTest)
		{
			BinaryHeapMaxPQ<int> maxPq;

			maxPq.insert(1);
			maxPq.insert(5);
			Assert::IsTrue(*maxPq.max() == 5);
			Assert::IsTrue(*maxPq.delMax() == 5);
			Assert::IsTrue(maxPq.size() == 1);
		}

		TEST_METHOD(BinaryHeapMaxPQ_InsertDeleteTest)
		{
			
			const int iterations = 3;
			BinaryHeapMaxPQ<int> maxPq;

			for (int i = 0; i < iterations; ++i) {
				maxPq.insert(i);
			}

			for (int i = iterations-1; i >= 0; --i) {
				Assert::IsTrue(i == *maxPq.delMax());
			}

			for (int i = 0; i < iterations; ++i) {
				maxPq.insert(i*2);
			}

			for (int i = iterations - 1; i >= 0; --i) {
				Assert::IsTrue(i*2 == *maxPq.delMax());
			}
		}

	};
}

#endif
