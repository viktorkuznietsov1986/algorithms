#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "HashSETWrapper.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(HashSetWrapperTest)
	{
	public:

		TEST_METHOD(HashSetWrapper_BasicFlowTest)
		{
			HashSETWrapper<char> st;
			st.add('E');
			st.add('A');
			st.add('S');
			st.add('Y');
			st.add('Q');
			st.add('U');
			st.add('E');
			st.add('T');
			st.add('I');
			st.add('O');
			st.add('N');


			Assert::IsTrue(st.size() == 10);
			Assert::IsFalse(st.contains('B'));
			Assert::IsTrue(st.contains('S'));
			st.Delete('E');
			Assert::IsFalse(st.contains('E'));
			Assert::IsTrue(st.size() == 9);
			st.add('E');
			Assert::IsTrue(st.contains('E'));
			Assert::IsTrue(st.size() == 10);

		}

	};
}

#endif
