#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "MSDSort.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(MSDSortTest)
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

		TEST_METHOD(MSDSort_BasicFlowTest)
		{
			std::vector<std::string> arr;
			arr.push_back("test");
			arr.push_back("abcd");
			arr.push_back("aaaa");
			arr.push_back("bold");
			arr.push_back("char");
			arr.push_back("baaa");
			arr.push_back("zdaa");
			arr.push_back("kxyz");
			MSDSort::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}

		TEST_METHOD(MSDSort_DifferentStringWidthTest)
		{
			std::vector<std::string> arr;
			arr.push_back("at");
			arr.push_back("home");
			arr.push_back("boo");
			arr.push_back("baby");
			arr.push_back("boy");
			arr.push_back("baaa");
			arr.push_back("zdaa");
			arr.push_back("kxyz");
			MSDSort::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}






	};
}

#endif
