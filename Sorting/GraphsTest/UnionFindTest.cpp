#include "stdafx.h"
#include "CppUnitTest.h"
#include "UnionFind.h"

#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsTest
{
	TEST_CLASS(UnionFindTest)
	{
	public:

		TEST_METHOD(UnionFind_BasicFlow)
		{
			auto uf = std::make_unique<UnionFind>(10);
			uf->connect(1, 2);
			uf->connect(2, 5);
			Assert::IsTrue(uf->connected(1, 5));
			Assert::IsFalse(uf->connected(1, 6));

			uf->connect(6, 7);
			uf->connect(9, 3);
			Assert::IsTrue(uf->connected(6, 7));
			Assert::IsFalse(uf->connected(1, 6));

			uf->connect(5, 3);
			Assert::IsTrue(uf->connected(1, 9));

		}

	};
}