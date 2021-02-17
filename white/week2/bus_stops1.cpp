#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::vector<std::pair<std::string,std::vector<std::string>>> bs;
	int n;
	std::cin >> n;
	for(int i=0; i<n; ++i)
	{
		std::string query;
		std::cin >> query;
		if(query=="NEW_BUS")
		{
			std::string bus;
			int n_stops;
			std::cin >> bus >> n_stops;
			std::pair<std::string, std::vector<std::string>> tmp_pair;
			tmp_pair.first = bus;
			for(int i=0; i<n_stops; ++i)
			{
				std::string stop;
				std::cin >> stop;
				tmp_pair.second.push_back(stop);
			}
			bs.push_back(tmp_pair);
		}
		else if(query=="BUSES_FOR_STOP")
		{
			std::string stop;
			std::cin >> stop;
			int count = 0;
			for(const auto& [bus,stops] : bs)
			{
				if(std::find(stops.begin(), stops.end(), stop) != stops.end())
				{
					++count;
					std::cout << bus << ' ';
				}
			}
			if(count==0) { std::cout << "No stop"; }
			std::cout << std::endl;
		}
		else if(query=="STOPS_FOR_BUS")
		{
			std::string curr_bus;
			std::cin >> curr_bus;
			auto it_curr_bus = std::find_if(bs.begin(), bs.end(), [&curr_bus](const auto& p){ return p.first==curr_bus; });
			if(it_curr_bus==bs.end()) { std::cout << "No bus" << std::endl; continue; }
			for(const auto& stop : it_curr_bus->second)
			{
				std::cout << "Stop " << stop << ": ";
				int interchange_count = 0;
				for(const auto& [bus,stops] : bs)
				{
					if(bus==it_curr_bus->first) { continue; }
					if(std::find(stops.begin(), stops.end(), stop) != stops.end())
					{
						++interchange_count;
						std::cout << bus << ' ';
					}
				}
				if(interchange_count==0) { std::cout << "no interchange" << std::endl; }
				else{ std::cout << std::endl; }
			}
		}
		else if(query=="ALL_BUSES")
		{
			if(bs.size()==0) { std::cout << "No buses" << std::endl; continue; }
			auto sorted = bs;
			std::sort(sorted.begin(), sorted.end(), [](auto& lhs, auto& rhs){ return lhs.first < rhs.first; });
			for(const auto [bus,stops] : sorted)
			{
				std::cout << "Bus " << bus << ": ";
				for(const auto& stop : stops)
				{
					std::cout << stop << ' ';
				}
				std::cout << std::endl;
			}
		}
	}
}
