#include <iostream>
#include <vector>

int main(void)
{
    int w, x, h;
    std::cin >> w >> x >> h;
    std::vector<std::vector<std::vector<int>>> v(w + 1, std::vector<std::vector<int>>(x + 1, std::vector<int>(h + 1, 1)));
    int q;
    std::cin >> q;
    while (q--)
    {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i(x1); i <= x2; ++i)
        {
            for (int j(y1); j <= y2; ++j)
            {
                for (int k(z1); k <= z2; ++k)
                {
                    v[i][j][k] = 0;
                }
            }
        }
    }
    int ans(0);
    for (int i(1); i <= w; ++i)
    {
        for (int j(1); j <= x; ++j)
        {
            for (int k(1); k <= h; ++k)
            {
                ans += v[i][j][k];
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}