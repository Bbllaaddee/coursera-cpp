#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::map<std::string, std::set<std::string>> s;
	for(int i=0; i<n; ++i)
	{
		std::string query;
		std::cin >> query;
		if(query=="ADD")
		{
			std::string w1;
			std::string w2;
			std::cin >> w1 >> w2;
			s[w1].insert(w2);
			s[w2].insert(w1);
		}
		else if(query=="COUNT")
		{
			std::string word;
			std::cin >> word;
			std::cout << s[word].size() << std::endl;
		}
		else if(query=="CHECK")
		{
			std::string w1;
			std::string w2;
			std::cin >> w1 >> w2;
			if(s[w1].count(w2)) { std::cout << "YES" << std::endl; }
			else { std::cout << "NO" << std::endl; }
		}
	}
}
