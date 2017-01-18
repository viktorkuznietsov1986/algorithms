#ifdef WINDOWS

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Alphabet.h"
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	//char toChar(int index) const;
	//int toIndex(char c) const;
	//int R() const { return r; }
	//int lgR() const { return lgr; }
	//bool contains(char c) const { return toIndex(c) > -1; }
	//std::vector<int> toIndices(const std::string& s) const;
	//std::string toChars(const std::vector<int>& indices) const;

	TEST_CLASS(AlphabetTest)
	{
	
	public:

		TEST_METHOD(Alphabet_BasicFlowTest)
		{
			Alphabet a("ABCDa");
			Assert::IsTrue(a.R() == 5);
			Assert::IsTrue(a.lgR() == 2);
			Assert::IsTrue(a.toChar(4) == 'a');
			Assert::IsTrue(a.toChar(1) == 'B');

			Assert::IsTrue(a.contains('C'));
			Assert::IsFalse(a.contains('c'));

		}

		TEST_METHOD(Alphabet_CheckToIndices)
		{
			Alphabet a("ABCDa");
			
			auto indices = a.toIndices("AAAAaCAD");
			std::vector<int> resToTest{ 0,0,0,0,4,2,0,3 };
			
			Assert::IsTrue(std::equal(indices.begin(), indices.end(), resToTest.begin(), resToTest.end()));
		}

		TEST_METHOD(Alphabet_CheckToChars)
		{
			Alphabet a("ABCDa");

			std::vector<int> testIndices{ 0,0,0,0,4,2,0,3 };
			auto chars = a.toChars(testIndices);

			Assert::IsTrue(chars == "AAAAaCAD");
		}

		TEST_METHOD(Alphabet_InvalidAlphabet)
		{
			auto func = [this] {Alphabet a("ABCDaa"); };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(Alphabet_ToIndicesInvalidSymbol)
		{
			auto func = [this] {Alphabet a("ABCDaa"); a.toIndices("DE"); };
			Assert::ExpectException<std::exception>(func);
		}

	};
}

#endif
