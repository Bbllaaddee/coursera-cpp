#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <numeric>

class Rational {
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);
	friend Rational operator*(const Rational&, const Rational&);
	friend Rational operator/(const Rational&, const Rational&);
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);

public:
    Rational() {
		Rational(0,1);
    }

    Rational(int numerator, int denominator) : num(numerator), denom(denominator)
	{
		if(denominator==0) { throw std::invalid_argument(""); }
		simplify();
	}

    int Numerator() const { return num; }

    int Denominator() const { return denom; }

private:
	int num;
	int denom;

	void simplify()
	{
		if(denom < 0) { num *= -1; denom *= -1; }
		int gcd_curr = std::gcd(num,denom);
		while(gcd_curr!=1)
		{
			num /= gcd_curr;
			denom /= gcd_curr;
			gcd_curr = std::gcd(num,denom);
		}
	}
};

bool operator==(const Rational& rhs, const Rational& lhs)
{
	return (lhs.num==rhs.num) && (lhs.denom==rhs.denom);
}

Rational operator+(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num*r2.denom + r2.num*r1.denom, r1.denom*r2.denom);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num*r2.denom - r2.num*r1.denom, r1.denom*r2.denom);
}

std::istream& operator>>(std::istream& inp, Rational& r)
{
	int num;
	int denom;
	inp >> num;
	if(inp.fail()) { return inp; }
	if(inp.peek()!='/') { return inp; }
	inp.ignore(1);
	inp >> denom;
	if(inp.fail()) { return inp; }
	Rational tmp(num, denom);
	r = tmp;
	return inp;
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
	return out << r.num << '/' << r.denom;
}

bool operator<(const Rational& rhs, const Rational& lhs)
{
	return rhs.num*lhs.denom < lhs.num*rhs.denom;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num*r2.num, r1.denom*r2.denom);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	if(r2.num==0) { throw std::domain_error(""); }
	return Rational(r1.num*r2.denom, r1.denom*r2.num);
}

int main()
{
	Rational r1;
	Rational r2;
	char operation;
	try { std::cin >> r1; }
	catch(std::invalid_argument& e) { std::cout << "Invalid argument" << std::endl; return 1; }
	std::cin >> operation;
	try { std::cin >> r2; }
	catch(std::invalid_argument& e) { std::cout << "Invalid argument" << std::endl; return 1; }
	if(operation=='+') { std::cout << r1 + r2 << std::endl; }
	else if(operation=='-') { std::cout << r1 - r2 << std::endl; }
	else if(operation=='*') { std::cout << r1 * r2 << std::endl; }
	else if(operation=='/')
	{
		try { std::cout << r1 / r2 << std::endl; }
		catch(std::domain_error& e) { std::cout << "Division by zero" << std::endl; }
	}
}
