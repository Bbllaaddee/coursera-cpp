#include <algorithm>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& vec)
{
	std::vector<int> ans;
	std::reverse_copy(vec.begin(), vec.end(), std::back_inserter(ans));
	return ans;
}
