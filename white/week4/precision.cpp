#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
	std::ifstream inp("input.txt");
	double num;
	while(inp >> num)
	{
		std::cout << std::fixed << std::setprecision(3) << num << std::endl;
	}
}
