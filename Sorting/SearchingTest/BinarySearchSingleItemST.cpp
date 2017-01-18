#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearchSingleItemST.h"
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{
	typedef BinarySearchSingleItemST<int, std::string>::Item Item;

	TEST_CLASS(BinarySearchSingleItemSTTest)
	{
	public:

		TEST_METHOD(BinarySearchSingleItemST_BasicFlowTest)
		{
			// TODO: Your test code here
			BinarySearchSingleItemST<int, std::string> st;
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

		TEST_METHOD(BinarySearchSingleItemST_ConstructionTest)
		{
			// TODO: Your test code here
			std::vector<Item> items;
			items.push_back(Item(1, "test1"));
			items.push_back(Item(5, "test5"));
			items.push_back(Item(2, "test2"));

			BinarySearchSingleItemST<int, std::string> st(items);
			

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
		}

		TEST_METHOD(BinarySearchSingleItemST_Caching)
		{
			// TODO: Your test code here
			BinarySearchSingleItemST<int, std::string> st;
			st.put(1, "test1");
			st.put(5, "test5");
			st.put(2, "test2");

			Assert::IsTrue(st.size() == 3);
			Assert::IsFalse(st.contains(3));
			Assert::IsTrue(st.contains(5));
			Assert::IsTrue(st.contains(5));
			Assert::IsTrue(*st.get(5) == "test5");
			Assert::IsTrue(*st.get(5) == "test5");
			st.Delete(5);
			Assert::IsFalse(st.contains(5));
			Assert::IsTrue(st.size() == 2);
			st.put(3, "test3");
			Assert::IsTrue(*st.get(3) == "test3");
			Assert::IsTrue(*st.get(3) == "test3");
			Assert::IsTrue(st.size() == 3);
		}

	};
}

#endif
