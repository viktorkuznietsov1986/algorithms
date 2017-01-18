#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "MultiMapBST.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(MultiMapBSTTest)
	{

	public:



		TEST_METHOD(MultiMapBST_BasicFlowTest)
		{
			MultiMapBST<char, int> st;
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

			Assert::IsTrue(st.size() == 12);
			Assert::IsFalse(st.contains('B'));
			Assert::IsTrue(st.contains('S'));
			/*Assert::IsTrue(*st.get('E') == 12);*/
			st.Delete('E');
			Assert::IsFalse(st.contains('E'));
			Assert::IsTrue(st.size() == 10);
			st.put('E', 18);
			Assert::IsTrue(*st.get('E') == 18);
			Assert::IsTrue(st.size() == 11);
		}


	};
}

#endif
