#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream inp("input.txt");
	int n_rows;
	int n_cols;
	inp >> n_rows >> n_cols;
	std::string line;
	std::getline(inp, line);
	for(int i=0; i<n_rows; ++i)
	{
		for(int j=0; j<n_cols; ++j)
		{
			std::getline(inp, line, ',');
			std::cout << std::left << std::setw(10) << line;
		}
	}
}
