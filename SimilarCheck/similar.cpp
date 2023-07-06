#include <string>
#include <stdexcept>
#include <iostream>
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

	void checkAlphabetExist(const string& str1, bool* alphabetExist)
	{
		for (auto ch : str1)
		{
			alphabetExist[ch - 'A'] = true;
		}
	}

	int countAlphabetExist(bool* alphabetExist)
	{
		int cnt = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (alphabetExist[i] == false) continue;
			cnt++;
		}
		return cnt;
	}

	int getTotalAlphabetCnt(const string& str1, const string& str2)
	{
		bool alphabetExist[26] = { false };
		checkAlphabetExist(str1, alphabetExist);
		checkAlphabetExist(str2, alphabetExist);
		return countAlphabetExist(alphabetExist);
	}

	void invalidateExist(bool *alphabetExist, char ch)
	{
		alphabetExist[ch - 'A'] = false;
	}

	int countDifferentAlphabet(const string& str, bool* alphabetExist)
	{
		int cnt = 0;
		for (auto ch: str)
		{
			if (alphabetExist[ch - 'A'] == false) continue;
			cnt++;
			invalidateExist(alphabetExist, ch);
		}
		return cnt;
	}

	int getSameAlphabetCnt(const string& str1, const string& str2)
	{
		bool alphabetExist[26] = { false };
		checkAlphabetExist(str1, alphabetExist);

		return countDifferentAlphabet(str2, alphabetExist);
	}

	int checkAlphabet(const string& str1, const string& str2)
	{
		int totalCnt = getTotalAlphabetCnt(str1, str2);
		int sameCnt = getSameAlphabetCnt(str1, str2);

		return ((double)sameCnt/totalCnt)*40;
	}

	void assertIllegalArgument(const string& str)
	{
		//대문자만 고려합니다.
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