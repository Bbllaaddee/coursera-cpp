#include <iostream>
#include <cmath>

int main()
{
	int a;
	int b;
	std::cin >> a >> b;
	int start;
	if(a%2==0) { start = a; }
	else if(a%2==1) { start = a+1; }
	for(int i=start; i<=b; i+=2) { std::cout << i << ' '; }
}
