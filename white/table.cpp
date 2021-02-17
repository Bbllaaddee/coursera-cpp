#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream inp("input.txt");
	int n_rows;
	int n_cols;
	inp >> n_rows >> n_cols;
	std::vector<int> table(n_rows*n_cols);
	for(int i=0; i<n_rows; ++i)
	{
		for(int j=0; j<n_cols; ++j)
		{
			std::string tmp;
			std::getline(inp, tmp);
			std::istringstream iss(tmp);

		}
	}
}
