#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <iostream>
#include <string>

class Person
{
public:
	Person() = delete;
	Person(const std::string& first_name, const std::string& last_name, int year) : _birth_year(year)
	{
		first_names[year] = first_name;
		last_names[year] = last_name;
	}

	void ChangeFirstName(int year, const std::string& first_name)
	{
		if(year<_birth_year) { return; }
		first_names[year] = first_name;
	}
	void ChangeLastName (int year, const std::string& last_name )
	{
		if(year<_birth_year) { return; }
		last_names [year] = last_name;
	}

	std::string GetFullName(int year) const
	{
		if(year<_birth_year) { return "No person"; }
		auto curr_last_name = last_names.lower_bound(year);
		auto curr_first_name = first_names.lower_bound(year);
		if(curr_last_name==last_names.end() && curr_first_name==first_names.end()) { return "Incognito"; }
		else if(curr_first_name==first_names.end()) { return curr_last_name->second + " with unknown first name"; }
		else if(curr_last_name==last_names.end()) { return curr_first_name->second + " with unknown last name"; }
		else { return curr_first_name->second + ' ' + curr_last_name->second; }
	}
	std::string GetFullNameWithHistory(int year) const
	{
		if(year<_birth_year) { return "No person"; }
		auto curr_last_name = last_names.lower_bound(year);
		auto curr_first_name = first_names.lower_bound(year);
		if(curr_last_name==last_names.end() && curr_first_name==first_names.end()) { return "Incognito"; }
		else if(curr_first_name==first_names.end())
		{
			auto all_prev_last_names = get_history(curr_last_name, last_names.end());
			return parse_names(all_prev_last_names) + " with unknown first name";
		}
		else if(curr_last_name==last_names.end())
		{
			auto all_prev_first_names = get_history(curr_first_name, first_names.end());
			return parse_names(all_prev_first_names) + " with unknown last name";
		}
		else
		{
			auto all_prev_first_names = get_history(curr_first_name, first_names.end());
			auto all_prev_last_names = get_history(curr_last_name, last_names.end());
			return parse_names(all_prev_first_names) + ' ' + parse_names(all_prev_last_names);
		}
	}

private:
	const int _birth_year;
	std::map<int, std::string, std::greater<>> first_names;
	std::map<int, std::string, std::greater<>> last_names;

	std::string parse_names(std::vector<std::string> names) const
	{
		std::ostringstream out;
		out << names[0];
		if(names.size()==1) { return out.str(); }
		for(size_t i=1; i<names.size(); ++i)
		{
			if(i==1) { out << " (" << names[i]; }
			else { out << ", " << names[i]; }
			if(i==names.size()-1) { out << ')'; }
		}
		return out.str();
	}

	std::vector<std::string> get_history(typename std::map<int, std::string>::const_iterator begin,
			                             typename std::map<int, std::string>::const_iterator end) const
	{
		std::vector<std::string> all_prev_names;
		for(auto it=begin; it!=end; ++it) { all_prev_names.push_back(it->second); }
		all_prev_names.erase(std::unique(all_prev_names.begin(), all_prev_names.end()), all_prev_names.end());
		return all_prev_names;
	}
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
	  std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
	  std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  return 0;
}
