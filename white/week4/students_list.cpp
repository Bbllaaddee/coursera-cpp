#include <iostream>
#include <string> 
#include <vector>

struct Student
{
	std::string name;
	std::string surname;
	int b_d;
	int b_m;
	int b_y;
};

int main()
{
	int n;
	std::cin >> n;
	std::vector<Student> students(n);
	for(size_t i=0; i<n; ++i) { std::cin >> students[i].name >> students[i].surname >> students[i].b_d >> students[i].b_m >> students[i].b_y; }
	int n_queries;
	std::cin >> n_queries;
	for(int n=0; n<n_queries; ++n)
	{
		std::string query;
		std::cin >> query;
		if(query=="name")
		{
			size_t number;
			std::cin >> number;
			try
			{
				std::cout << students.at(number-1).name << ' ' << students.at(number-1).surname << std::endl;
			}
			catch(std::out_of_range) { std::cout << "bad request" << std::endl; }
		}
		else if(query=="date")
		{
			int number;
			std::cin >> number;
			try
			{
				std::cout << students.at(number-1).b_d << '.' << students.at(number-1).b_m << '.' << students.at(number-1).b_y << std::endl;
			}
			catch(std::out_of_range) { std::cout << "bad request" << std::endl; }
		}
		else { int number; std::cin >> number; std::cout << "bad request" << std::endl; }
	}
}
