#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<bool> people;
	std::string query;
	std::getline(std::cin, query); // fix for EOL character to be eaten
	for(int i=0; i<n; ++i)
	{
		std::getline(std::cin, query);
		if(query=="") { return 0; }
		std::istringstream inp(query);
		std::string action;
		inp >> action;
		if(action=="WORRY_COUNT") { std::cout << std::count(people.begin(), people.end(), true) << std::endl; continue; }
		int spec;
		inp >> spec;
		if(action=="COME")
		{
			if(spec>0) { std::fill_n(std::back_inserter(people), spec, false); }
			else if(spec<0) { people.erase(people.end()+spec, people.end()); }
		}
		else if(action=="WORRY") { people[spec] = true; }
		else if(action=="QUIET") { people[spec] = false; }
	}
}
