#include <fstream>
#include <iostream>

int main()
{
	std::ifstream inp("input.txt");
	std::string tmp;
	while(std::getline(inp, tmp))
	{
		std::cout << tmp << std::endl;
	}
}
