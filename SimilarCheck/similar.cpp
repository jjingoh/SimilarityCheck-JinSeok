#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker
{
public:
	int checkLength(const string& str1, const string& str2)
	{
		int long_length = std::max(str1.size(), str2.size());
		int small_length = std::min(str1.size(), str2.size());
		int gap = long_length - small_length;
		return (1 - gap / (double)small_length) * 60;
	}

	int checkAlphabet(const string& str1, const string& str2)
	{
		return 40;
	}

	void assertIllegalArgument(const string& str)
	{
		for (auto ch : str)
		{
			if (ch >= 'A' && ch <= 'Z') continue;
			throw invalid_argument("Must be Capital Alphabet");
		}
	}

	int checkSimilarity(const string& str1, const string& str2)
	{
		assertIllegalArgument(str1);
		assertIllegalArgument(str2);
		int lengthScore = checkLength(str1, str2);
		int alphabetScore = checkAlphabet(str1, str2);
		return lengthScore + alphabetScore;
	}
};