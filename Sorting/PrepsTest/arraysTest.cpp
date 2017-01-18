#include "stdafx.h"
#include "CppUnitTest.h"

#include "arrays.h"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrepsTest
{		
	TEST_CLASS(ArraysTest)
	{
	public:
		
		TEST_METHOD(sumOfMostCommonIntRuntime_PositiveCase)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(4);
			a.push_back(2);
			a.push_back(2);

			Assert::AreEqual(sumOfMostCommonIntRuntime(a), 6);
		}

		TEST_METHOD(sumOfMostCommonIntRuntime_NoElements)
		{
			std::vector<int> a;
			
			Assert::AreEqual(sumOfMostCommonIntRuntime(a), -1);
		}

		TEST_METHOD(sumOfMostCommonIntRuntime_NoCommonInteger)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			
			Assert::AreEqual(sumOfMostCommonIntRuntime(a), 2);
		}

		TEST_METHOD(sumOfMostCommonIntSpace_PositiveCase)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(4);
			a.push_back(2);
			a.push_back(2);

			Assert::AreEqual(sumOfMostCommonIntSpace(a), 6);
		}

		TEST_METHOD(sumOfMostCommonIntSpace_NoElements)
		{
			std::vector<int> a;

			Assert::AreEqual(sumOfMostCommonIntSpace(a), -1);
		}

		TEST_METHOD(sumOfMostCommonIntSpace_NoCommonInteger)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);

			Assert::AreEqual(sumOfMostCommonIntSpace(a), 2);
		}

		TEST_METHOD(findMostCommonPositiveInteger_BasicWorkflow)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(5);
			a.push_back(5);
			a.push_back(5);
			a.push_back(5);

			Assert::AreEqual(findMostCommonPositiveInteger(a), 5);
		}

		TEST_METHOD(findMostCommonPositiveInteger_EmptyArray)
		{
			std::vector<int> a;

			Assert::AreEqual(findMostCommonPositiveInteger(a), -1);
		}

		TEST_METHOD(findMostCommonPositiveInteger_HasNegative)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(5);
			a.push_back(-5);
			a.push_back(5);
			a.push_back(5);

			Assert::AreEqual(findMostCommonPositiveInteger(a), -1);
		}

		TEST_METHOD(findMostCommonPositiveInteger_DistinctValues)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);

			Assert::AreEqual(findMostCommonPositiveInteger(a), -1);
		}

		TEST_METHOD(maxProfitMultipleTrades_BasicFlow)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(1);
			a.push_back(5);
			a.push_back(4);
			a.push_back(9);
			a.push_back(6);
			a.push_back(7);

			Assert::AreEqual(maxProfitMultipleTrades(a), 14);
		}
		
		TEST_METHOD(maxProfitMultipleTrades_DistinctValuesIncreasingOrder)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);

			Assert::AreEqual(maxProfitMultipleTrades(a), 4);
		}

		TEST_METHOD(maxProfitMultipleTrades_DistinctValuesDecreasingOrder)
		{
			std::vector<int> a;
			a.push_back(6);
			a.push_back(5);
			a.push_back(4);
			a.push_back(2);

			Assert::AreEqual(maxProfitMultipleTrades(a), 0);
		}

		TEST_METHOD(maxProfitMultipleTrades_ZeroLength)
		{
			std::vector<int> a;

			Assert::AreEqual(maxProfitMultipleTrades(a), 0);
		}

		TEST_METHOD(maxProfitSingleTrade_BasicFlow)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(1);
			a.push_back(5);
			a.push_back(4);
			a.push_back(9);
			a.push_back(6);
			a.push_back(7);

			Assert::AreEqual(maxProfitSingleTrade(a), 5);
		}

		TEST_METHOD(maxProfitSingleTrade_DistinctValuesIncreasingOrder)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);

			Assert::AreEqual(maxProfitSingleTrade(a), 4);
		}

		TEST_METHOD(maxProfitSingleTrade_DistinctValuesDecreasingOrder)
		{
			std::vector<int> a;
			a.push_back(6);
			a.push_back(5);
			a.push_back(4);
			a.push_back(2);

			Assert::AreEqual(maxProfitSingleTrade(a), 0);
		}

		TEST_METHOD(maxProfitSingleTrade_ZeroLength)
		{
			std::vector<int> a;

			Assert::AreEqual(maxProfitSingleTrade(a), 0);
		}

		TEST_METHOD(maxProfitTwoTrades_BasicFlow)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);
			a.push_back(1);
			a.push_back(5);
			a.push_back(4);
			a.push_back(9);
			a.push_back(6);
			a.push_back(7);

			Assert::AreEqual(maxProfitTwoTrades(a), 9);
		}

		TEST_METHOD(maxProfitTwoTrades_DistinctValuesIncreasingOrder)
		{
			std::vector<int> a;
			a.push_back(2);
			a.push_back(4);
			a.push_back(5);
			a.push_back(6);

			Assert::AreEqual(maxProfitTwoTrades(a), 4);
		}

		TEST_METHOD(maxProfitTwoTrades_DistinctValuesDecreasingOrder)
		{
			std::vector<int> a;
			a.push_back(6);
			a.push_back(5);
			a.push_back(4);
			a.push_back(2);

			Assert::AreEqual(maxProfitTwoTrades(a), 0);
		}

		TEST_METHOD(maxProfitTwoTrades_ZeroLength)
		{
			std::vector<int> a;

			Assert::AreEqual(maxProfitTwoTrades(a), 0);
		}

		TEST_METHOD(encode_NullInput)
		{
			Assert::AreEqual(encode(nullptr), nullptr);
		}

		TEST_METHOD(encode_BasicPositiveCase)
		{
			auto str = "AAABBCCCCC";
			auto encoded = encode(str);
			Assert::AreEqual(strcmp(encoded, "3A2B5C"), 0);
			free(encoded);
		}

		TEST_METHOD(encode_DistinctItems)
		{
			auto str = "ABCD";
			auto encoded = encode(str);
			Assert::AreEqual(strcmp(encoded, "04ABCD"), 0);
			free(encoded);
		}

		TEST_METHOD(encode_MixedItems)
		{
			auto str = "AAAAABCDEFFFF";
			auto encoded = encode(str);
			Assert::AreEqual(strcmp(encoded, "5A04BCDE4F"), 0);
			free(encoded);
		}

		TEST_METHOD(encode_SingleItem)
		{
			auto str = "A";
			auto encoded = encode(str);
			Assert::AreEqual(strcmp(encoded, "01A"), 0);
			free(encoded);
		}

		TEST_METHOD(decode_NullInput)
		{
			Assert::AreEqual(decode(nullptr), nullptr);
		}

		TEST_METHOD(decode_BasicPositiveCase)
		{
			auto str = "3A2B5C";
			auto decoded = decode(str);
			Assert::AreEqual(strcmp(decoded, "AAABBCCCCC"), 0);
			free(decoded);
		}

		TEST_METHOD(decode_DistinctItems)
		{
			auto str = "04ABCD";
			auto decoded = decode(str);
			Assert::AreEqual(strcmp(decoded, "ABCD"), 0);
			free(decoded);
		}

		TEST_METHOD(decode_MixedItems)
		{
			auto str = "5A04BCDE4F";
			auto decoded = decode(str);
			Assert::AreEqual(strcmp(decoded, "AAAAABCDEFFFF"), 0);
			free(decoded);
		}

		TEST_METHOD(decode_SingleItem)
		{
			auto str = "01A";
			auto decoded = decode(str);
			Assert::AreEqual(strcmp(decoded, "A"), 0);
			free(decoded);
		}

	};
}