#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
	std::string str;
	std::getline(std::cin, str);
	std::istringstream inp(str);
	size_t n;
	inp >> n;
	std::vector<int> numbers(n);
	for(size_t i=0; i<n; ++i) { inp >> numbers[i]; }
	std::sort(numbers.begin(), numbers.end(), [](auto lhs, auto rhs){ return std::abs(lhs)<std::abs(rhs); });
	for(auto number : numbers) { std::cout << number << ' '; }
}
