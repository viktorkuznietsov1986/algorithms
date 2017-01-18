#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "UnorderedLinkedListMaxPQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(UnorderedLinkedListMaxPQTest)
	{
	public:

		TEST_METHOD(UnorderedLinkedListMaxPQ_BasicFlowTest)
		{
			UnorderedLinkedListMaxPQ<int> maxPq;

			maxPq.insert(1);
			maxPq.insert(5);
			Assert::IsTrue(*maxPq.max() == 5);
			Assert::IsTrue(*maxPq.delMax() == 5);
			Assert::IsTrue(maxPq.size() == 1);
		}

		TEST_METHOD(UnorderedLinkedListMaxPQ_InsertDeleteTest)
		{
			UnorderedLinkedListMaxPQ<int> maxPq;
			const int iterations = 3;

			for (int i = 0; i <= iterations; ++i) {
				maxPq.insert(i);
			}

			for (int i = iterations; i >= 0; --i) {
				Assert::IsTrue(i == *maxPq.delMax());
			}
		}

	};
}

#endif
