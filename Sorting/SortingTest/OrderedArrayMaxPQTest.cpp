#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "OrderedArrayMaxPQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(OrderedArrayMaxPQTest)
	{
	public:

		TEST_METHOD(OrderedArrayMaxPQBasicFlowTest)
		{
			COrderedArrayMaxPQ<int> maxPq(5);

			maxPq.insert(1);
			maxPq.insert(5);
			maxPq.insert(2);
			maxPq.insert(6);
			Assert::IsTrue(*maxPq.max() == 6);
			Assert::IsTrue(*maxPq.delMax() == 6);
			Assert::IsTrue(maxPq.size() == 3);
		}

		TEST_METHOD(OrderedArrayMaxPQResizeTest)
		{
			COrderedArrayMaxPQ<int> maxPq(2);

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
