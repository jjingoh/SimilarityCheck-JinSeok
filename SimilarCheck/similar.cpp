#include <string>

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
};