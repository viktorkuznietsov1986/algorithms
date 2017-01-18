#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BSTNr.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{
	

	TEST_CLASS(BinarySearchSTNrTest)
	{
		bool checkQueueOrdered(std::queue<char>& a, bool ascending) {
			auto prev = a.front();
			a.pop();

			while (!a.empty()) {
				auto curr = a.front();
				a.pop();

				if (ascending) {
					if (prev > curr) {
						return false;
					}
				}
				else {
					if (prev < curr) {
						return false;
					}
				}

				prev = curr;
			}

			return true;
		}

	public:

		TEST_METHOD(BSTNr_BasicFlowTest)
		{
			BSTNr<char, int> st;
			st.put('E', 1);
			st.put('A', 10);
			st.put('S', 2);
			st.put('Y', 3);
			st.put('Q', 1);
			st.put('U', 1);
			st.put('E', 12);
			st.put('S', 3);
			st.put('T', 1);
			st.put('I', 2);
			st.put('O', 1);
			st.put('N', 1);

			Assert::IsTrue(st.height() == 6);
			Assert::IsTrue(st.height_linear() == 6);

			//int a = st.avgCompares();

			Assert::IsTrue(st.size() == 10);
			Assert::IsFalse(st.contains('B'));
			Assert::IsTrue(st.contains('S'));
			Assert::IsTrue(*st.get('E') == 12);
			st.Delete('E');
			Assert::IsTrue(st.height() == 5);
			Assert::IsTrue(st.height_linear() == 5);
			Assert::IsFalse(st.contains('E'));
			Assert::IsTrue(st.size() == 9);
			st.put('E', 18);
			Assert::IsTrue(*st.get('E') == 18);
			Assert::IsTrue(st.size() == 10);

			Assert::IsTrue(st.min() == 'A');
			Assert::IsTrue(st.max() == 'Y');

			Assert::IsTrue(st.floor('J') == 'I');
			Assert::IsTrue(st.ceiling('B') == 'E');
			Assert::IsTrue(st.select(0) == 'A');
			Assert::IsTrue(st.rank('A') == 0);
			Assert::IsTrue(st.select(st.rank('I')) == 'I');

			auto a = st.keys();
			Assert::IsTrue(a.size() == 10);
			Assert::IsTrue(checkQueueOrdered(a, true), L"incorrect keys collection");

			auto b = st.keysReverse();
			Assert::IsTrue(b.size() == 10);
			Assert::IsTrue(checkQueueOrdered(b, false), L"incorrect keys collection");

			Assert::IsTrue(st.min() < st.max());
		}

		TEST_METHOD(BSTNr_CachingTest)
		{
			BSTNr<char, int> st;
			st.put('E', 1);
			st.put('E', 12);
			st.put('A', 10);
			st.put('S', 2);
			st.put('S', 3);
			st.put('Y', 3);
			st.put('Q', 1);
			st.put('U', 1);
			st.put('T', 1);
			st.put('I', 2);
			st.put('O', 1);
			st.put('N', 1);

			Assert::IsTrue(st.size() == 10);

			Assert::IsTrue(*st.get('Y') == *st.get('Y'));
		}

	};
}

#endif
