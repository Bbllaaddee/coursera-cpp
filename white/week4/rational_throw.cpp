#include <iostream>
#include <numeric>
#include <exception>
using namespace std;

class Rational {
	friend Rational operator/(const Rational&, const Rational&);
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

Rational operator/(const Rational& r1, const Rational& r2)
{
	if(r2.num==0) { throw std::domain_error(""); }
	return Rational(r1.num*r2.denom, r1.denom*r2.num);
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
