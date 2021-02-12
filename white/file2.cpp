#include <fstream>
#include <iostream>

int main()
{
	std::ifstream inp("input.txt");
	std::string tmp;
	std::ofstream out("output.txt");
	while(std::getline(inp, tmp))
	{
		out << tmp << std::endl;
	}
}
