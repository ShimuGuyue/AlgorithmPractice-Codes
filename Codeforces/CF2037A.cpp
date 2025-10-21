#include <iostream>
#include <map>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
	
	int t(1);
	std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
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
		ans += ii.second / 2;
	}
	std::cout << ans << std::endl;
}