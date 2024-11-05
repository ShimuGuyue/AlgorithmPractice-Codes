#include <iostream>
#include <vector>

int Count(std::vector<std::vector<char>>& grid, int x, int y, int n);

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
    int ans(2500);
    for (int w(0); w < n - 2; ++w) // white end
    {
        for (int b(w + 1); b < n - 1; ++b) // blue end
        {
            int count(Count(grid, w, b, n));
            ans = std::min(ans, count);

        }
    }
    std::cout << ans << std::endl;
    return 0;
}

int Count(std::vector<std::vector<char>>& grid, int x, int y, int n)
{
    int ans(0);
    for (int i(0); i <= x; ++i)
    {
        for (int color : grid[i])
        {
            if (color != 'W')
                ++ans;
        }
    }
    for (int i(x + 1); i <= y; ++i)
    {
        for (int color : grid[i])
        {
            if (color != 'B')
                ++ans;
        }
    }
    for (int i(y + 1); i < n; ++i)
    {
        for (int color : grid[i])
        {
            if (color != 'R')
                ++ans;
        }
    }
    return ans;
}