#include<bits/stdc++.h>

void Solve(void)
{
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int64_t>> grid(n + 1, std::vector<int64_t>(m + 1));
    while (q--)
    {
        int mod;
        std::cin >> mod;
        if (mod == 1)
        {
            int l, r, x;
            std::cin >> l >> r >> x;
            for (int i(1); i <= n; ++i)
            {
                for (int j(l); j <= r; ++j)
                {
                    grid[i][j] += x;
                }
            }
        }
        else if (mod == 2)
        {
            int i, x;
            std::cin >> i >> x;
            for (int j(1); j <= m; ++j)
            {
                grid[i][j] = x;
            }
        }
        else
        {
            int i, j;
            std::cin >> i >> j;
            std::cout << grid[i][j] << std::endl;
        }
    }
}

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(".in.in"  , "r", stdin );
    freopen(".out.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int t(1);
    //std::cin >> t;
    while (t--)
        Solve();
    return 0;
}