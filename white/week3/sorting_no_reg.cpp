#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::istringstream inp(input);
	size_t n;
	inp >> n;
	std::vector<std::string> ans(n);
	for(size_t i=0; i<n; ++i) { inp >> ans[i]; }

	std::sort(ans.begin(), ans.end(), [](std::string lhs, std::string rhs)
	{
		for(auto& letter : lhs) { letter = std::tolower(letter); }
		for(auto& letter : rhs) { letter = std::tolower(letter); }
		return lhs < rhs;
	});
	for(const auto& str : ans) { std::cout << str << ' '; }
}
