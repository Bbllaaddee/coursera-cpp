#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);

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

bool operator<(const Rational& rhs, const Rational& lhs)
{
	return rhs.num*lhs.denom < lhs.num*rhs.denom;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
