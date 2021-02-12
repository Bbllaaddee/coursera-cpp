#include <string>
#include <iostream>
#include <algorithm>

class ReversibleString
{
private:
	std::string _str;
public:
	ReversibleString() = default;
	ReversibleString(const std::string str) : _str(str) {}

	std::string ToString() const { return _str; } 
	void Reverse() { std::reverse(_str.begin(), _str.end()); }
};
