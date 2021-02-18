#include <iostream>
#include <numeric>
using namespace std;


class Rational {
public:
    Rational() {
		Rational(0,1);
    }

    Rational(int numerator, int denominator) : num(numerator), denom(denominator)
	{
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
