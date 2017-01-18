#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedListSort.h"
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(LinkedListSortTest)
	{
	
	public:

		TEST_METHOD(LinkedListSort_BasicFlowTest)
		{
			std::list<std::string> lst{ "test" , "abcd", "aaaa", "bold", "char", "baaa", "zdaa", "kxyz" };
			
			LinkedListSort::sort(lst);

			std::list<std::string> result{ "aaaa" , "abcd", "baaa", "bold", "char", "kxyz", "test", "zdaa" };

			Assert::IsTrue(std::equal(lst.begin(), lst.end(), result.begin(), result.end()));

		}

		TEST_METHOD(LinkedListSort_DifferentStringWidthTest)
		{
			std::list<std::string> lst{ "at", "home", "boo", "baby", "boy", "baaa", "zdaa", "kxyz" };
			LinkedListSort::sort(lst);

			std::list<std::string> result{ "at","baaa","baby","boo","boy", "home", "kxyz", "zdaa" };

			Assert::IsTrue(std::equal(lst.begin(), lst.end(), result.begin(), result.end()));

		}






	};
}

#endif
