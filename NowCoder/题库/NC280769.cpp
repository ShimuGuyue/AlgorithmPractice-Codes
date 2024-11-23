#include <iostream>
#include <vector>

int n, m;
std::string ans;
std::vector<std::vector<int>> grid;

void Dfs(int x, int y, int flag);
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
    std::cin >> n >> m;
    grid = std::vector<std::vector<int>>(n, std::vector<int>(m));
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < m; ++j)
        {
            std::cin >> grid[i][j];
        }
    }
    ans = "No";
    Dfs(0, 0, grid[0][0]);
    std::cout << ans << std::endl;
}

void Dfs(int x, int y, int flag)
{
    if (x == m - 1 && y == m - 1)
    {
        ans = "Yes";
        return;
    }

    if (x != n - 1 && grid[x + 1][y] == flag)
        Dfs(x + 1, y, flag);
    if (y != m - 1 && grid[x][y + 1] == flag)
        Dfs(x, y + 1, flag);
}