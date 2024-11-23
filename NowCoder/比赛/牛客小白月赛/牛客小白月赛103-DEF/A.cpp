#include <iostream>
#include <map>

void solve(void);

int main(void)
{
	int t(1);
	std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
	int n;
	std::cin >> n;
	std::map<int, int> counts;
	while (n--)
	{
		int a;
		std::cin >> a;
		++counts[a];
	}
	int ans(0);
	for (std::pair<int, int> ii : counts)
	{
		if (ii.second >= 3)
		{
			ans = ii.first * 3;
			break;
		}
	}
	if (ans == 0)
		std::cout << "no" << std::endl;
	else
		std::cout << "yes" << std::endl
				  << ans << std::endl;
}