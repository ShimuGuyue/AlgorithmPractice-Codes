#include <iostream>
#include <vector>
#include <map>

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
	std::map<int, int> b;
	std::map<int, int> r;
	int n;
	std::cin >> n;
	std::vector<int> values(n);
	for (int& value : values)
	{
		std::cin >> value;
	}
	std::string color;
	std::cin >> color;
    for (int i(0); i < n; ++i)
	{
		if (color[i] == 'B')
			++b[values[i]];
		else // if (color[i] == 'R')
			++r[values[i]];
	}
	int64_t ans(0);
	for (std::pair<int, int> ii : b)
	{
		ans += b[ii.first] * r[ii.first];
	}
	std::cout << ans << std::endl;
}