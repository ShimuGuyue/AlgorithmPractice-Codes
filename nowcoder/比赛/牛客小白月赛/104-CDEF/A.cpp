#include <iostream>

namespace solve
{
	void Solve(void);
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
#endif
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    int n, x, y, z, t;
	std::cin >> n >> x >> y >> z >> t;
	int ans(x + y);
	int sum(z + t);
	while (n--)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a + b > ans && c <= sum)
			ans = a + b;
	}
	std::cout << ans << std::endl;
}