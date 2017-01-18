#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "UnorderedArrayMaxPQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{		
	TEST_CLASS(UnorderedArrayMaxPQTest)
	{
	public:
		
		TEST_METHOD(UnorderedArrayMaxPQ_BasicFlowTest)
		{
			CUnorderedArrayMaxPQ<int> maxPq(5);

			maxPq.insert(1);
			maxPq.insert(5);
			Assert::IsTrue(*maxPq.max() == 5);
			Assert::IsTrue(*maxPq.delMax() == 5);
			Assert::IsTrue(maxPq.size() == 1);
		}

		TEST_METHOD(UnorderedArrayMaxPQ_ResizeTest)
		{
			CUnorderedArrayMaxPQ<int> maxPq(2);

			for (int i = 0; i < 20; ++i) {
				maxPq.insert(i);
			}

			for (int i = 0; i < 18; ++i) {
				maxPq.delMax();
			}
		}

	};
}

#endif
