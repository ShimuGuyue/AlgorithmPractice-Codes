#include <iostream>
#include <vector>
#include <algorithm>

int dxy[4][2]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n;
std::vector<std::vector<int>> grid;

void Dfs(int x, int y, std::vector<std::pair<int, int>>& paths, bool& in);
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

void Solve(void)
{
	// int n;
	std::cin >> n;
	// std::vector<std::vector<int>> grid(n, std::vector<int>(n));
	grid = std::vector<std::vector<int>>(n, std::vector<int>(n));
	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			std::cin >> grid[i][j];
		}
	}

	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			if (grid[i][j] != 0)
				continue;
			std::vector<std::pair<int, int>> paths;
			bool in(true);
			paths.push_back({i, j});
			Dfs(i, j, paths, in);
			if (in)
			{
				for (std::pair<int ,int> ii : paths)
				{
					grid[ii.first][ii.second] = 2;
				}
			}
			else
			{
				for (std::pair<int ,int> ii : paths)
				{
					grid[ii.first][ii.second] = 3;
				}
			}
		}
	}

	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			if (grid[i][j] == 3)
				grid[i][j] = 0;
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Dfs(int x, int y, std::vector<std::pair<int, int>>& paths, bool& in)
{
	for (int i(0); i < 4; ++i)
	{
		if (x + dxy[i][0] < 0 || x + dxy[i][0] >= n)
		{
			in = false;
			continue;
		}
		if (y + dxy[i][1] < 0 || y + dxy[i][1] >= n)
		{
			in = false;
			continue;
		}
		bool once(false);
		for (std::pair<int, int> ii : paths)
		{
			if (ii == std::pair<int, int>{x + dxy[i][0], y + dxy[i][1]})
			{
				once = true;
				break;
			}
		}
		if (once)
		{
			continue;
		}
		if (grid[x + dxy[i][0]][y + dxy[i][1]] == 0)
		{
			paths.push_back({x + dxy[i][0], y + dxy[i][1]});
			Dfs(x + dxy[i][0], y + dxy[i][1], paths, in);
		}
	}
}