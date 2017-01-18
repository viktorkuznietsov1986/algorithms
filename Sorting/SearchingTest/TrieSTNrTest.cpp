#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "TrieSTNr.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(TrieSTNrTest)
	{

	public:

		TEST_METHOD(TrieSTNr_BasicFlowTest)
		{
			auto s = std::make_unique<TrieSTNr<int>>();
			s->put("see", 1);
			s->put("sea", 2);
			s->put("seaside", 0);

			Assert::AreEqual(s->size(), 3);

			Assert::AreEqual(*(s->get("see")), 1);
			Assert::AreEqual(*(s->get("sea")), 2);
			Assert::AreEqual(*(s->get("seaside")), 0);
			Assert::IsTrue(s->get("pe") == nullptr);
			Assert::IsTrue(s->get("seas") == nullptr);
		}



	};
}

#endif
