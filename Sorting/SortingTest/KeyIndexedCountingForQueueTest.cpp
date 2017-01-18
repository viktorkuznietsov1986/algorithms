#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "KeyIndexedCountingForQueue.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(KeyIndexedCountingForQueueTest)
	{
	private:
		static bool isSorted(std::vector<std::queue<char>>& a) {
			bool sorted = true;
			for (size_t i = 0; i < a.size() - 1; ++i) {
				auto curr = a[i].front();
				auto next = a[i + 1].front();
				if (curr > next) {
					sorted = false;
					break;
				}
			}

			return sorted;
		}

		static std::queue<char> queueFromString(const std::string& s) {
			std::queue<char> result;
			for (int i = 0; i < s.size(); ++i) {
				result.push(s[i]);
			}

			return result;
		}

	public:

		TEST_METHOD(KeyIndexedCountingForQueue_BasicFlowTest)
		{
			std::vector<std::queue<char>> arr;
			
			arr.push_back(queueFromString("test"));
			arr.push_back(queueFromString("abcd"));
			arr.push_back(queueFromString("aaaa"));
			arr.push_back(queueFromString("bold"));
			arr.push_back(queueFromString("char"));
			arr.push_back(queueFromString("baaa"));
			arr.push_back(queueFromString("zdaa"));
			arr.push_back(queueFromString("kxyz"));
			KeyIndexedCountingForQueue::sort(arr);

			Assert::IsTrue(isSorted(arr));

		}






	};
}

#endif
