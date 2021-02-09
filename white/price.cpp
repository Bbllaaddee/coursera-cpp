#include <iostream>

int main()
{
	double price; // N
	double thresh1; // A
	double thresh2; // B
	double discount1; // X
	double discount2; // Y
	std::cin >> price >> thresh1 >> thresh2 >> discount1 >> discount2;
	
	if(price>thresh2) { std::cout << price*(1 - discount2/100); return 0; }
	else if(price>thresh1) { std::cout << price*(1 - discount1/100); return 0; }
	else { std::cout << price; }
	return 0;
}
