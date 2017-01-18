#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "TSTNr.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(TSTNrTest)
	{

	public:

		TEST_METHOD(TSTNr_BasicFlowTest)
		{
			auto s = std::make_unique<TSTNr<int>>();
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
