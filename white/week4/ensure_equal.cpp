#include <string>
#include <exception>
#include <stdexcept>

void EnsureEqual(const std::string& left, const std::string& right)
{
	if(left != right)
	{
		throw std::runtime_error(left + " != " + right);
	}
}

int main()
{
	EnsureEqual("a", "b");
};
