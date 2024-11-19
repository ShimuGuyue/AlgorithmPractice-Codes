#include <iostream>
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
    int n;
	std::cin >> n;
	std::map<int, int64_t> m;
	while (n--)
	{
		int a;
		std::cin >> a;
		++m[a];
		int64_t ans(0);
		for (std::pair<int, int64_t> ii : m)
		{
			ans += ii.second * (ii.second - 1) / 2;
		}
		std::cout << ans << " ";
	}
	std::cout << std::endl;
} 