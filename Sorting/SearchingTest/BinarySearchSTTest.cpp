#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearchST.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{
	TEST_CLASS(BinarySearchSTTest)
	{
	public:

		TEST_METHOD(BinarySearchST_BasicFlowTest)
		{
			// TODO: Your test code here
			BinarySearchST<int, std::string> st;
			st.put(1, "test1");
			st.put(5, "test5");
			st.put(2, "test2");

			Assert::IsTrue(st.size() == 3);
			Assert::IsFalse(st.contains(3));
			Assert::IsTrue(st.contains(5));
			Assert::IsTrue(*st.get(5) == "test5");
			st.Delete(5);
			Assert::IsFalse(st.contains(5));
			Assert::IsTrue(st.size() == 2);
			st.put(3, "test3");
			Assert::IsTrue(*st.get(3) == "test3");
			Assert::IsTrue(st.size() == 3);

			Assert::IsTrue(st.min() < st.max());
		}

	};
}

#endif
