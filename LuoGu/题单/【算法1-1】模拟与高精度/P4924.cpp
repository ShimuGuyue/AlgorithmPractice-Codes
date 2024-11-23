//O2
#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i(0), flag(1); i < n; ++i)
    {
        for (int j(0); j < n; ++j, ++flag)
        {
            grid[i][j] = flag;
        }
    }
    while (m--)
    {
        int x, y, r, z;
        std::cin >> x >> y >> r >> z;
        --x; x -= r;
        --y; y -= r;
        r = r * 2 + 1;

        std::vector<std::vector<int>> temp(r, std::vector<int>(r));
        if (z == 0)
        {
            for (int i(0); i < r; ++i)
            {
                for (int j(0); j < r; ++j)
                {
                    temp[j][r - 1 - i] = grid[x + i][y + j];
                }
            }
        }
        else // z == 1
        {
            for (int i(0); i < r; ++i)
            {
                for (int j(0); j < r; ++j)
                {
                    temp[r - 1 - j][i] = grid[x + i][y + j];
                }
            }
        }
        
        for (int i(0); i < r; ++i)
        {
            for (int j(0); j < r; ++j)
            {
                grid[x + i][y + j] = temp[i][j];
            }
        }
    }

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