#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "TrieST.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(TrieSTTest)
	{
		
	public:

		TEST_METHOD(TrieST_BasicFlowTest)
		{
			auto s = std::make_unique<TrieST<int>>();
			s->put("see", 1);
			s->put("sea", 2);
			s->put("seaside", 0);

			Assert::AreEqual(s->size(), 3);

			auto c = s->ceiling("aa");

			Assert::IsTrue(c == "sea");

			auto f = s->floor("seas");
			Assert::IsTrue(f == "seaside");

			auto r = s->rank("aa");
			Assert::IsTrue(r == 0);

			auto sel = s->select(0);
			Assert::IsTrue(sel == "sea");

			Assert::IsTrue(s->select(s->rank("see")) == "see");

			Assert::AreEqual(*(s->get("see")), 1);
			Assert::AreEqual(*(s->get("sea")), 2);
			Assert::AreEqual(*(s->get("seaside")), 0);
			Assert::IsTrue(s->get("pe") == nullptr);
			Assert::IsTrue(s->get("seas") == nullptr);

			
		}
	};
}

#endif
