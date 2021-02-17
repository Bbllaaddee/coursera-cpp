#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	int count = 0;
	std::map<std::vector<std::string>, int> bs;
	for(int i=0; i<n; ++i)
	{
		int n_stops;
		std::cin >> n_stops;
		std::vector<std::string> stops(n_stops);
		for(int j=0; j<n_stops; ++j) { std::cin >> stops[j]; }
		if(count==0)
		{
			bs[stops] = ++count;
			std::cout << "New bus " << count << std::endl;
		}
		else if(bs.count(stops))
		{
			std::cout << "Already exists for " << bs.find(stops)->second << std::endl;
		}
		else
		{
			bs[stops] = ++count;
			std::cout << "New bus " << count << std::endl;
		}
	}
}
