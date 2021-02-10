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
	void ChangeFirstName(int year, const std::string& first_name) { first_names[year] = first_name; }
	void ChangeLastName (int year, const std::string& last_name ) { last_names [year] = last_name;  }
	std::string GetFullName(int year)
	{
		auto curr_last_name = last_names.lower_bound(year);
		auto curr_first_name = first_names.lower_bound(year);
		if(curr_last_name==last_names.end() && curr_first_name==first_names.end()) { return "Incognito"; }
		else if(curr_first_name==first_names.end()) { return curr_last_name->second + " with unknown first name"; }
		else if(curr_last_name==last_names.end()) { return curr_first_name->second + " with unknown last name"; }
		else { return curr_first_name->second + ' ' + curr_last_name->second; }
	}
	std::string GetFullNameWithHistory(int year)
	{
		auto curr_last_name = last_names.lower_bound(year);
		auto curr_first_name = first_names.lower_bound(year);
		if(curr_last_name==last_names.end() && curr_first_name==first_names.end()) { return "Incognito"; }
		else if(curr_first_name==first_names.end())
		{
			std::vector<std::string> all_prev_last_names;
			for(auto it=curr_last_name; it!=last_names.end(); ++it) { all_prev_last_names.push_back(it->second); }
			std::unique(all_prev_last_names.begin(), all_prev_last_names.end());
			std::ostringstream out;
			out << curr_last_name->second << " (";
			for(const auto& name : all_prev_last_names) { out << name << ' '; }
			out << ") ";
			return out.str();
		}
	}

private:
	std::map<int, std::string, std::greater<>> first_names;
	std::map<int, std::string, std::greater<>> last_names;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;

  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;

  return 0;
}
