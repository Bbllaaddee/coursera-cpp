#include <iostream>
#include <set>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::set<std::string> s;
	for(int i=0; i<n; ++i)
	{
		std::string tmp;
		std::cin >> tmp;
		s.insert(tmp);
	}
	std::cout << s.size() << std::endl;
}
