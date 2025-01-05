#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t = 1;
	//std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	int n, m, k;
	std::cin >> n >> m >> k;
	if (k < std::max(n, m))
	{
		std::cout << -1 << std::endl;
		return;
	}
	std::vector<std::vector<int>> grid(n, std::vector<int>(m));
	if (n >= m)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			grid[i][i % m] = 1;
			--k;
		}
		grid[n - 1][(n - 1) % m] = k;
	}
	else
	{
		for (int i = 0; i < m - 1; ++i)
		{
			grid[i % n][i] = 1;
			--k;
		}
		grid[(m - 1) % n][m - 1] = k;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}