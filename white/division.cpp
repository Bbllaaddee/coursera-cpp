#include <iostream>

int main()
{
	int a;
	int b;
	std::cin >> a >> b;
	if(b==0) { std::cout << "Impossible";}
	else { std::cout << a/b; }
}
