#include <iostream>
#include <iomanip>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    int i(0), j(0);
    grid[i][j] = 1;
    int mode(1); // 1-r 2-d 3-l 4-u
    for (int k(2); k <= n * n; ++k)
    {
        if (mode == 1)
        {
            if (j == n - 1 || grid[i][j + 1])
            {
                ++i;
                mode = 2;
            }
            else
                ++j;
        }
        else if (mode == 2)
        {
            if (i == n - 1 || grid[i + 1][j])
            {
                --j;
                mode = 3;
            }
            else
                ++i;
        }
        else if (mode == 3)
        {
            if (j == 0 || grid[i][j - 1])
            {
                --i;
                mode = 4;
            }
            else
                --j;
        }
        else if (mode == 4)
        {
            if (i == 0 || grid[i - 1][j])
            {
                ++j;
                mode = 1;
            }
            else
                --i;
        }
        grid[i][j] = k;
    }

    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            std::cout << std::setw(3) << grid[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}