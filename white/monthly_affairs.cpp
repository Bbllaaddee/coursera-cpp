#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

void next_month(std::vector<std::vector<std::string>>& vec)
{
	static int curr_month = 1;
	std::map<int,int> calendar = 
	{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31} };
	++curr_month;
	int diff = calendar[curr_month] - vec.size();
	if(diff<0)
	{
		for(auto it = vec.end()+diff; it!= vec.end(); ++it)
		{
			
		}
	}
}

int main()
{
	std::vector<std::vector<std::string>> month(31);
	int n;
	std::cin >> n;
	std::string query;
	std::getline(std::cin, query);
	for(int i=0; i<n; ++i)
	{
		std::getline(std::cin, query);
		std::istringstream inp(query);
		std::string action;
		inp >> action;
		if(action=="NEXT") { next_month(month); continue; }
		int spec;
		inp >> spec;
		if(action=="DUMP")
		{
			for(const auto& item : month[spec]) { std::cout << item << ' '; }
			std::cout << std::endl;
			continue;
		}
		std::string note;
		inp >> note;
		if(action=="ADD")
		{
			month[spec].push_back(note);
		}
	}
}
