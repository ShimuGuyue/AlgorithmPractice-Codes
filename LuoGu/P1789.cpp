#include <iostream>
#include <vector>

int main(void)
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        --x; --y;
        for (int i(-2); i <= 2; ++i)
        {
            if (0 <= x + i && x + i < n)
                grid[x + i][y] = 1;
        }
        for (int i(-2); i <= 2; ++i)
        {
            if (0 <= y + i && y + i < n)
                grid[x][y + i] = 1;
        }
        if (0 <= x - 1 && x - 1 < n && 0 <= y - 1 && y - 1 < n)
            grid[x - 1][y - 1] = 1;
        if (0 <= x - 1 && x - 1 < n && 0 <= y + 1 && y + 1 < n)
            grid[x - 1][y + 1] = 1;
        if (0 <= x + 1 && x + 1 < n && 0 <= y - 1 && y - 1 < n)
            grid[x + 1][y - 1] = 1;
        if (0 <= x + 1 && x + 1 < n && 0 <= y + 1 && y + 1 < n)
            grid[x + 1][y + 1] = 1;
    }
    while (k--)
    {
        int o, p;
        std::cin >> o >> p;
        --o; --p;
        for (int i(-2); i <= 2; ++i)
        {
            if (0 <= o + i && o + i < n)
                for (int j(-2); j <= 2; ++j)
                {
                    if (0 <= p + j && p + j < n)
                        grid[o + i][p + j] = 1;
                }
        }
    }
    int ans(0);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            if (grid[i][j] == 0)
                ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}