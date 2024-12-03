#include <iostream>
#include <vector>
#include <climits>

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
	std::vector<std::vector<int>> grid(2, std::vector<int>(n));
	for (int i(0); i < 2; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			std::cin >> grid[i][j];
		}
	}

	std::vector<std::vector<int>> flags(2, std::vector<int>(n));

	int ans(0);
	for (int i(0); i < n; ++i)
	{
		if (grid[0][i] > grid[1][i])
		{
			ans += grid[0][i];
			flags[0][i] = 1;
		}
		else
		{
			ans += grid[1][i];
			flags[1][i] = 1;
		}
	}

	int max(INT_MIN);
	for (int i(0); i < 2; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			if (flags[i][j] == 1)
				continue;
			if (grid[i][j] > max)
				max = grid[i][j];
		}
	}
	ans += max;

	std::cout << ans << std::endl;
}