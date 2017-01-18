#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "SubstringBrute.h"
#include <memory>
#include <algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(SubstringBruteTest)
	{

	public:

		TEST_METHOD(SubstringBrute_BasicFlowTest)
		{
			auto s = std::make_unique<SubstringBrute>("bac");
			
			Assert::IsTrue(s->search("aaaa") == 4);
			Assert::IsTrue(s->search("ba") == 2);
			Assert::IsTrue(s->search("acabac") == 3);
			Assert::IsTrue(s->count("abacedabacer") == 2);

			auto searchResult = s->searchAll("abacedabacer");
			std::list<int> testResult{ 1,7 };

			Assert::IsTrue(std::equal(searchResult.begin(), searchResult.end(), testResult.begin(), testResult.end()));
		}



	};
}

#endif
