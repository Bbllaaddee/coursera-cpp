#include <map>
#include <string>
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::map<std::string, std::string> cc;
	for(int i=0; i<n; ++i)
	{
		std::string query;
		std::cin >> query;
		if(query=="DUMP")
		{
			if(cc.size()==0) { std::cout << "There are no countries in the world" << std::endl; }
			else
			{
				for(const auto& [country,capital] : cc) { std::cout << country << '/' << capital << ' '; }
				std::cout << std::endl;
			}
		}
		else if(query=="ABOUT")
		{
			std::string country;
			std::cin >> country;
			try
			{
				const auto& capital = cc.at(country);
				std::cout << "Country " << country << " has capital " << capital << std::endl;
			}
			catch(std::out_of_range) { std::cout << "Country " << country << " doesn't exist" << std::endl; continue; }
		}
		else if(query=="RENAME")
		{
			std::string country_old;
			std::string country_new;
			std::cin >> country_old >> country_new;
			bool country_old_exists = cc.count(country_old);
			bool country_new_exists = cc.count(country_new);
			if(country_new_exists || !country_old_exists || country_old==country_new)
			{ std::cout << "Incorrect rename, skip" << std::endl; }
			else
			{
				const auto capital = cc[country_old];
				std::cout << "Country " << country_old << " with capital " << capital << " has been renamed to " << 
					country_new << std::endl;
				cc.erase(country_old);
				cc[country_new] = capital;
			}
		}
		else if(query=="CHANGE_CAPITAL")
		{
			std::string country;
			std::string new_capital;
			std::cin >> country >> new_capital;
			bool country_exists = cc.count(country);
			if(!country_exists)
			{
				cc[country] = new_capital;
				std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
			}
			else
			{
				auto old_capital = cc[country];
				if(old_capital==new_capital) { std::cout << "Country " <<  country << " hasn't changed its capital" << std::endl; }
				else
				{ 
					cc[country] = new_capital;
					std::cout << "Country " << country << " has changed its capital from " << old_capital
						<< " to " << new_capital << std::endl;
				}
			}
		}
	}
}
