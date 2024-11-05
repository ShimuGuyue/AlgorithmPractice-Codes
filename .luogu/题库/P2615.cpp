#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> grid(n + 1, std::vector<int>(n + 1));
    int lastI(1), lastJ(n / 2 + 1);
    grid[lastI][lastJ] = 1;
    for (int i(2); i <= n * n; ++i)
    {
        if (lastI == 1 && lastJ != n)
        {
            lastI = n; lastJ = lastJ + 1;
        }
        else if (lastI != 1 && lastJ == n)
        {
            lastI = lastI - 1; lastJ = 1;
        }
        else if (lastI == 1 && lastJ == n)
        {
            lastI = lastI + 1; lastJ = lastJ;
        }
        else if (lastI != 1 && lastJ != n)
        {
            if(grid[lastI - 1][lastJ + 1] == 0)
            {
                lastI = lastI - 1; lastJ = lastJ + 1;
            }
            else
            {
                lastI = lastI + 1; lastJ = lastJ;
            }
        }

        grid[lastI][lastJ] = i;
    }
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= n; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}