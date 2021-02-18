#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream inp("input.txt");
	int n_rows;
	int n_cols;
	inp >> n_rows >> n_cols;
	std::vector<int> table(n_rows*n_cols);
	std::string tmp;
	std::getline(inp,tmp);
	for(int i=0; i<n_rows; ++i)
	{
		std::string line;
		std::getline(inp,line);
		std::istringstream ls(line);
		for(int j=0; j<n_cols; ++j)
		{
			std::string col;
			std::getline(ls,col, ',');
			std::cout << std::setw(10) << col;
			if(j != (n_cols-1)) { std::cout << ' '; }
		}
		if(i != (n_rows-1)) { std::cout << std::endl; }
	}
}
