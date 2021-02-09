#include <iostream>
#include <string>

int main()
{
	std::string a;
	std::string b;
	std::string c;
	std::cin >> a >> b >> c;
	if(a<=b && a<=c) { std::cout << a; }
	else if(b<=c && b<=a) { std::cout << b; }
	else { std::cout << c; }
}
