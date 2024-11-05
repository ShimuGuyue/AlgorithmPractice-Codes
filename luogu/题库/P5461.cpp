#include <iostream>
#include <vector>
#include <cmath>

void solve(std::vector<std::vector<int>>& grid, int x, int y, int n);

int main(void)
{
    int n;
    std::cin >> n;
    n = pow(2, n);
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 1));
    solve(grid, 0, 0, n);
    for (std::vector<int> vi : grid)
    {
        for (int i : vi)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

void solve(std::vector<std::vector<int>>& grid, int x, int y, int n)
{
    if (n == 1)
        return;

    n /= 2;

    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            grid[x + i][y + j] = 0;
        }
    }
    solve(grid, x + n, y    , n);
    solve(grid, x    , y + n, n);
    solve(grid, x + n, y + n, n);
}