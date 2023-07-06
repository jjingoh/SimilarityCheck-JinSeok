#include "pch.h"
#include "../SimilarCheck/similar.cpp"
#include <string>
#include <vector>

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, LengthCheck) {
	vector < tuple<string, string, int> > cases = {
		{"ASD", "DSA", 60},
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