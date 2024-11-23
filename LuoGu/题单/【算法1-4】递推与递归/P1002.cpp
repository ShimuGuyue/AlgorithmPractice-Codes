#include <iostream>
#include <vector>

int main(void)
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::vector<int64_t>> grid(n + 1, std::vector<int64_t>(m + 1));
    for (int i(0); i <= n; ++i)
    {
        for (int j(0); j <= m; ++j)
        {
            if ((i == x && j == y)
                || (i == x - 1 && j == y - 2) || (i == x - 2 && j == y - 1)
                || (i == x - 1 && j == y + 2) || (i == x - 2 && j == y + 1)
                || (i == x + 1 && j == y - 2) || (i == x + 2 && j == y - 1)
                || (i == x + 1 && j == y + 2) || (i == x + 2 && j == y + 1))
                grid[i][j] = 0;
            else if (i == 0 && j == 0)
                grid[i][j] = 1;
            else if (i == 0)
                grid[i][j] = grid[i][j - 1];
            else if (j == 0)
                grid[i][j] = grid[i - 1][j];
            else
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    int64_t ans(grid[n][m]);
    std::cout << ans << std::endl;
    return 0;
}