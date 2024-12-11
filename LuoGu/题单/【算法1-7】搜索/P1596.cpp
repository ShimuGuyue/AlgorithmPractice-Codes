#include <iostream>
#include <vector>

int dxy[8][2]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int n, m;
std::vector<std::vector<char>> grid;

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t(1);
	//std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Dfs(int x, int y);

void Solve(void)
{
	// int n, m;
	std::cin >> n >> m;
	// std::vector<std::vector<char>> grid(n, std::vector<char>(m));
	grid = std::vector<std::vector<char>>(n, std::vector<char>(m));
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < m; ++j)
		{
			std::cin >> grid[i][j];
		}
	}

	int ans(0);
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < m; ++j)
		{
			if (grid[i][j] == 'W')
			{
				++ans;
				Dfs(i, j);
			}
		}
	}
	std::cout << ans << std::endl;
}

void Dfs(int x, int y)
{
	grid[x][y] = '.';
	for (int i(0); i < 8; ++i)
	{
		if (x + dxy[i][0] < 0 || x + dxy[i][0] >= n)
			continue;
		if (y + dxy[i][1] < 0 || y + dxy[i][1] >= m)
			continue;
		if (grid[x + dxy[i][0]][y + dxy[i][1]] == 'W')
			Dfs(x + dxy[i][0], y + dxy[i][1]);
	}
}