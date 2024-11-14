#include <iostream>
#include <cmath>

void Solve(void);

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
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
    int n, c;
	std::cin >> n >> c;
	n -= 2 + std::to_string(c).size();
	int64_t max(pow(10, n - 1));
	int ans(0);
	for (int i(0); i < max && i <= c; ++i)
	{
		int j(c - i);
		if (std::to_string(i).size() + std::to_string(j).size() == n)
			++ans;
	}
	std::cout << ans << std::endl;
}