#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	std::string a;
	std::cin >> a;
	auto first = std::find(a.begin(), a.end(), 'f');
	if(first==a.end()) { std::cout << -2; return 0; }
	auto second = std::find(first+1, a.end(), 'f');
	if(second==a.end()) { std::cout << -1; return 0; }
	else { std::cout << std::distance(a.begin(), second); }
}
