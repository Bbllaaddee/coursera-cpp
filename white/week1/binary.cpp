#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
	int a;
	std::cin >> a;
	std::stringstream out;
	while(a>=2)
	{
		if(a%2==1) { out << 1; }
		else { out << 0; }
		a = a/2;
	}
	out << a;

	std::string ans = out.str();
	std::reverse(ans.begin(), ans.end());
	std::cout << ans;
}
