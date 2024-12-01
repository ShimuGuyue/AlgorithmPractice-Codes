#include <iostream>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    // 关闭输入输出缓存，使效率提升
    std::ios::sync_with_stdio(false);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
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
    int n;
	std::cin >> n;
	if (n % 4 == 1)
		std::cout << 0 << std::endl;
	else if (n % 4 == 2)
		std::cout << n + 1 << std::endl;
	else if (n % 4 == 3)
		std::cout << 1 << std::endl;
	else if (n % 4 == 0)
		std::cout << n << std::endl;
}

/**
 * void Solve(void)
{
	for (int n(1); n <= 16; ++n)
	{
		std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
		for (int i(1); i <= n; ++i)
		{
			for (int j(1); j <= n; ++j)
			{
				a[i][j] = i ^ j;
			}
		}
		for (int k(1); k <= n; ++k)
		{
			for (int i(1); i <= n; ++i)
			{
				for (int j(1); j <= n; ++j)
				{
					a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
		int ans(a[1][1]);
		for (int i(2); i <= n; ++i)
		{
			ans ^= a[1][i];
		}
		std::cout << n << " : " << ans << std::endl;
	}
}
 */