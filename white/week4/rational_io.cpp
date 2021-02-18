#include <iostream>
#include <numeric>
#include <sstream>
using namespace std;

class Rational {

	friend bool operator==(const Rational&, const Rational&);
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream& inp, Rational&);

public:
    Rational() : num(0), denom(1) { }
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

// Реализуйте для класса Rational операторы << и >>
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}