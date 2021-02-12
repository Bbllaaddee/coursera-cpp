#include <vector>

struct Incognizable
{
	std::vector<int> a;
	Incognizable(std::initializer_list<int> lst) : a(lst) {}
	Incognizable() = default;
};
