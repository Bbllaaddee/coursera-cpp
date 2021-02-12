#include <algorithm>
#include <string>

bool IsPalindrom(const std::string& word)
{
	std::string reversed;
	std::reverse_copy(word.begin(), word.end(), std::back_inserter(reversed));
	return word == reversed;
}
