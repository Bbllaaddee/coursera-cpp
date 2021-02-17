#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::map<std::string,std::vector<std::string>>> bs;
	int n;
	std::cin >> n;
	std::cout << n;
	for(int i=0; i<n; ++i)
	{
		std::string query;
		std::cin >> query;
		if(query=="NEW_BUS")
		{
			std::string bus;
			int n_stops;
			std::cin >> bus >> n_stops;
			std::map<std::string, std::vector<std::string>> tmp_map;
			tmp_map[bus] = {};
			for(int i=0; i<n_stops; ++n)
			{
				std::string stop;
				std::cin >> stop;
				tmp_map[bus].push_back(stop);
			}
			bs.push_back(tmp_map);
		}
		else if(query=="BUSES_FOR_STOP")
		{
			std::string stop;
			std::cin >> stop;
			int count = 0;
			for(const auto& bus_and_stops : bs)
			{
				for(const auto& [bus,stops] : bus_and_stops)
				{
					if(std::find(stops.begin(), stops.end(), stop) != stops.end())
					{
						++count;
						std::cout << bus << ' ';
					}
				}
			}
			if(count==0) { std::cout << "No stop"; }
			std::cout << std::endl;
		}
		else if(query=="STOPS_FOR_BUS")
		{}
		else if(query=="ALL_BUSES")
		{}
	}
}
