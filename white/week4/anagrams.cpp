#include <iostream>
#include <set>

int main()
{
	int n;
	std::cin >> n;
	for(int i=0; i<n; ++i)
	{
		std::string w1;
		std::string w2;
		std::cin >> w1 >> w2;
		std::multiset<char> s1;
		std::multiset<char> s2;
		for(auto letter : w1) { s1.insert(letter); }
		for(auto letter : w2) { s2.insert(letter); }
		if(s1==s2) { std::cout << "YES" << std::endl; }
		else { std::cout << "NO" << std::endl; }
	}
}
