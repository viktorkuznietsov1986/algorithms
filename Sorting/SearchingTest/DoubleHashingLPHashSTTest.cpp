#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "DoubleHashingLPHashST.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(DoubleHashingLPHashSTTest)
	{

	public:



		TEST_METHOD(DoubleHashingLPHashST_BasicFlowTest)
		{
			DoubleHashingLPHashST<char, int> st;
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

			Assert::IsTrue(*st.get('Y') == *st.get('Y'));

			Assert::IsTrue(st.size() == 10);
			Assert::IsFalse(st.contains('B'));
			Assert::IsTrue(st.contains('S'));
			Assert::IsTrue(*st.get('E') == 12);
			st.Delete('E');
			Assert::IsFalse(st.contains('E'));
			Assert::IsTrue(st.size() == 9);
			st.put('E', 18);
			Assert::IsTrue(*st.get('E') == 18);
			Assert::IsTrue(st.size() == 10);
		}


	};
}

#endif
