#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    for (std::vector<char>& vc : grid)
    {
        for (char& c : vc)
        {
            std::cin >> c;
        }
    }
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < m; ++j)
        {
            if (grid[i][j] == '*')
            {
                std::cout << "*";
                continue;
            }

            int count(0);
            if (i != 0 && grid[i - 1][j] == '*')
                ++count;
            if (j != 0 && grid[i][j - 1] == '*')
                ++count;
            if (i != n - 1 && grid[i + 1][j] == '*')
                ++count;
            if (j != m - 1 && grid[i][j + 1] == '*')
                ++count;
            if (i != 0 && j != 0 && grid[i - 1][j - 1] == '*')
                ++count;
            if (i != n - 1 && j != 0 && grid[i + 1][j - 1] == '*')
                ++count;
            if (i != 0 && j != m - 1 && grid[i - 1][j + 1] == '*')
                ++count;
            if (i != n - 1 && j != m - 1 && grid[i + 1][j + 1] == '*')
                ++count;
            std::cout << count;
        }
        std::cout << std::endl;
    }
    return 0;
}