#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

void next_month(std::vector<std::vector<std::string>>& vec)
{
	static size_t curr_month = 1;
	std::map<size_t,size_t> calendar = 
	{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31} };
	++curr_month;
	if(curr_month>12) { curr_month = 1; }
	if(calendar[curr_month]>vec.size()) { vec.resize(calendar[curr_month]); return; }
	else if(calendar[curr_month]<vec.size())
	{
		for(size_t i=calendar[curr_month]; i<vec.size(); ++i)
		{
			vec[calendar[curr_month]-1].insert(vec[calendar[curr_month]-1].end(), vec[i].begin(), vec[i].end());
		}
		vec.resize(calendar[curr_month]);
		return;
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
			std::cout << month[spec-1].size() << ' ';
			for(const auto& item : month[spec-1]) { std::cout << item << ' '; }
			std::cout << std::endl;
			continue;
		}
		std::string note;
		inp >> note;
		if(action=="ADD")
		{
			month[spec-1].push_back(note);
		}
	}
}
