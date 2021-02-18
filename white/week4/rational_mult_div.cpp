#include <iostream>
#include <numeric>
using namespace std;

class Rational {

	friend bool operator==(const Rational&, const Rational&);
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);
	friend Rational operator*(const Rational&, const Rational&);
	friend Rational operator/(const Rational&, const Rational&);

public:
    Rational() { Rational(0,1); }
    Rational(int numerator, int denominator) : num(numerator), denom(denominator) { simplify(); }

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

// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num*r2.num, r1.denom*r2.denom);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num*r2.denom, r1.denom*r2.num);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
