#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
	
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

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
    int n, k;
	std::cin >> n >> k;
	std::vector<int> as(n);
	for (int i(0); i < n; ++i)
	{
		std::cin >> as[i];
	}
	for (int i(0); i < n; ++i)
	{
		bool ok(true);
		for (int j(0); j < n; ++j)
		{
			if (i == j)
				continue;
			if (abs(as[i] - as[j]) % k == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			std::cout << "YES" << std::endl;
			std::cout << i + 1 << std::endl;
			return;
		}
	}
	std::cout << "NO" << std::endl;
}