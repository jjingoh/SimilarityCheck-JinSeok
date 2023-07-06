#include "pch.h"
#include "../SimilarCheck/similar.cpp"
#include <string>
#include <vector>

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
	void assertIllegalArgument(string str1, string str2)
	{
		try
		{
			checker.checkSimilarity(str1, str2);
			FAIL();
		}
		catch (exception e)
		{
			
		}
	}
};

TEST_F(SimilarityCheckerFixture, ThrowExceptionWhenInvalidCases) {
	vector < tuple<string, string> > cases = {
		{"ASD1", "DSA"},
		{"A", "BB1"},
		{"AAABBa", "BAA"},
		{"AA", "AAEb"},
	};
	for (auto& item : cases)
	{
		string str1, str2;
		std::tie(str1, str2) = item;
		assertIllegalArgument(str1, str2);
	}
}

TEST_F(SimilarityCheckerFixture, SameLengthCheck) {
	vector < tuple<string, string, int> > cases = {
		{"ASD", "DSA", 60}
	};
	for (auto& item : cases)
	{
		string str1, str2;
		int expected;
		std::tie(str1, str2, expected) = item;
		int score = checker.checkLength(str1, str2);
		EXPECT_EQ(expected, score);
	}
}


TEST_F(SimilarityCheckerFixture, DiffLengthCheck) {
	vector < tuple<string, string, int> > cases = {
		{"A", "BB", 0},
		{"AAABB", "BAA", 20},
		{"AA", "AAE", 30},
	};
	for (auto& item: cases)
	{
		string str1, str2;
		int expected;
		std::tie(str1, str2, expected) = item;
		int score = checker.checkLength(str1, str2);
		EXPECT_EQ(expected, score);
	}
}

TEST_F(SimilarityCheckerFixture, DoubleDiffLengthCheck) {
	vector < tuple<string, string, int> > cases = {
		{"AAAAA", "BB", 0}
	};
	for (auto& item : cases)
	{
		string str1, str2;
		int expected;
		std::tie(str1, str2, expected) = item;
		int score = checker.checkLength(str1, str2);
		EXPECT_EQ(expected, score);
	}
}
