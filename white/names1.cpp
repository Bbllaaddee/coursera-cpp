#include <map>
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

private:
	std::map<int, std::string, std::greater<>> first_names;
	std::map<int, std::string, std::greater<>> last_names;
};

int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	return 0;
}
