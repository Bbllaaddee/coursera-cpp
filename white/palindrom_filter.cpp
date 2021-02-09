#include <algorithm>
#include <vector>
#include <string>

bool IsPalindrom(const std::string& word)
{
	std::string reversed;
	std::reverse_copy(word.begin(), word.end(), std::back_inserter(reversed));
	return word == reversed;
}

std::vector<std::string> PalindromFilter(const std::vector<std::string>& words, int min_length)
{
	std::vector<std::string> ans;
	for(const auto& word : words)
	{
		if(IsPalindrom(word) && word.size() >= min_length) { ans.push_back(word); }
	}
	return ans;
}
