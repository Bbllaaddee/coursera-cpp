#include <vector>
#include <string>
#include <algorithm>

class SortedStrings
{
private:
	std::vector<std::string> _strings;
public:
	void AddString(const std::string& s) { _strings.push_back(s); }
	std::vector<std::string> GetSortedStrings()
	{
		std::vector<std::string> sorted = _strings;
		std::sort(sorted.begin(), sorted.end());
		return sorted;
	}
};
