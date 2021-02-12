#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> temps(n);
	for(int i=0; i<n; ++i)  { std::cin >> temps[i]; }
	int mean = std::accumulate(temps.begin(), temps.end(), 0)/temps.size();
	std::vector<int> ans;
	for(size_t i=0; i<temps.size(); ++i)
	{
		if(temps[i] > mean) { ans.push_back(i); }
	}
	std::cout << ans.size() << std::endl;
	for(auto item : ans) { std::cout << item << ' '; }
}
