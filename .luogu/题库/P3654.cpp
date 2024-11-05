#include <iostream>
#include <vector>

int main(void)
{
    int r, c, k;
    std::cin >> r >> c >> k;
    std::vector<std::vector<char>> grid(r, std::vector<char>(c));
    for (std::vector<char>& vc : grid)
    {
        for (char& c : vc)
        {
            std::cin >> c;
        }
    }
    int ans(0);
    for (int i(0); i < r; ++i)
    {
        for (int j(0); j < c - k + 1; ++j)
        {
            bool ok(true);
            for (int l(0); l < k; ++l)
            {
                if (grid[i][j + l] == '#')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ++ans;
        }
    }
    for (int i(0); i < r - k + 1; ++i)
    {
        for (int j(0); j < c; ++j)
        {
            bool ok(true);
            for (int l(0); l < k; ++l)
            {
                if (grid[i + l][j] == '#')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ++ans;
        }
    }
    if (k == 1)
        ans /= 2;
    std::cout << ans << std::endl;
    return 0;
}