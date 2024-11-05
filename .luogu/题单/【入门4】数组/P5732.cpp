#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> grid(n + 1, std::vector<int>(n + 1));
    for (int i(1); i <= n; ++i)
    {
        grid[i][1] = 1;
        for (int j(2); j < i; ++j)
        {
            grid[i][j] = grid[i - 1][j] + grid[i - 1][j - 1];
        }
        grid[i][i] = 1;
    }
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= i; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}