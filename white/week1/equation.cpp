#include <iostream>
#include <cmath>

int main()
{
	double a;
	double b;
	double c;
	std::cin >> a >> b >> c;
	
	if(a==0 && b==0) { return 0; }
	else if(a==0) { std::cout << -c/b;  return 0; }
	else if(b==0)
	{
		double ans_sq = -c/a;
		if(ans_sq<0) {  return 0; }
		else { std::cout << std::sqrt(ans_sq) << ' ' << -std::sqrt(ans_sq);}
	}
	else if(c==0) { std::cout << 0 << ' ' << -b/a; }
	else
	{
		double d = b*b - 4*a*c;
		if(d<0) {  return 0; }
		double x1 = (-b + std::sqrt(d))/(2*a);
		double x2 = (-b - std::sqrt(d))/(2*a);
		if(x1 != x2) { std::cout << x1 << ' ' << x2; }
		else { std::cout << x1; }
	}
}
