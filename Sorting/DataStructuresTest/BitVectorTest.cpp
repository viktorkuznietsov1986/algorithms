#include "CppUnitTest.h"

#include "BitVector.h"

#include <memory>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTest
{
	TEST_CLASS(BitVectorTest)
	{
	public:

		TEST_METHOD(BitVector_BasicFlowTest)
		{
			auto v = std::make_unique<BitVector>(100);
			v->add(50);
			v->add(5);
			v->add(90);
			v->add(0);
			v->add(11);
			v->add(4);
			v->add(2);
			v->add(85);
			v->add(3); 
			v->add(6); 
			v->add(1); 
			v->add(49); 
			v->add(12); 
			v->add(8); 
			v->add(7); 
			v->add(51);

			Assert::IsTrue(v->size() == 16);

			auto sortedArray = v->getSortedIntArray();
			std::vector<int> cmp{0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 49, 50, 51, 85, 90};

			Assert::IsTrue(std::equal(sortedArray.begin(), sortedArray.end(), cmp.begin(), cmp.end()));
		}

	};
}