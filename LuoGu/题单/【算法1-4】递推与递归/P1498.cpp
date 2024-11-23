// 参考教程 https://www.bilibili.com/video/BV18T411u7HG/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
#include <iostream>
#include <vector>

std::vector<std::vector<char>> grid;

void Dfs(int x, int y, int n);

int main(void)
{
    int n;
    std::cin >> n;

    int x(1 << n);
    int y(x * 2);
    grid = std::vector<std::vector<char>>(x, std::vector<char>(y, ' '));

    Dfs(0, 0, n);

    for (int i(0); i < x; ++i)
    {
        for (int j(0); j < y; ++j)
        {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

void Dfs(int x, int y, int n)
{
    if (n == 1)
    {
        grid[x][y+1] = '/';
        grid[x+1][y] = '/';
        grid[x][y+2] = '\\';
        grid[x+1][y+3] = '\\';
        grid[x+1][y+1] = '_';
        grid[x+1][y+2] = '_';
        return;
    }

    int dif(1 << n);
    Dfs(x, y + dif / 2, n - 1);
    Dfs(x + dif / 2, y, n - 1);
    Dfs(x + dif / 2, y + dif, n - 1);
}