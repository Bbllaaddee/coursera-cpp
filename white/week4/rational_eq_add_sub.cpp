#include <iostream>
#include <numeric>
using namespace std;

class Rational {

	friend bool operator==(const Rational&, const Rational&);
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);

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

// Реализуйте для класса Rational операторы ==, + и -
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
