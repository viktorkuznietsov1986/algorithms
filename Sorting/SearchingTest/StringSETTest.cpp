#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "StringSET.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchingTest
{


	TEST_CLASS(StringSETTest)
	{

	public:

		TEST_METHOD(StringSET_BasicFlowTest)
		{
			auto s = std::make_unique<StringSET>();
			s->add("see");
			s->add("sea");
			s->add("seaside");

			Assert::AreEqual(s->size(), 3);

			Assert::IsTrue(s->contains("see"));
			Assert::IsTrue(s->contains("sea"));
			Assert::IsTrue(s->contains("seaside"));
			Assert::IsFalse(s->contains("pe"));
			Assert::IsFalse(s->contains("seas"));

			std::string str = "sea seaside see";
			Assert::AreEqual(str, s->toString());

			s->Delete("sea");
			Assert::IsFalse(s->contains("sea"));

			s->Delete("seaside");
			Assert::IsFalse(s->contains("seaside"));
		}



	};
}

#endif
