// 参考教程 https://www.bilibili.com/video/BV1yz4y177XW/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> f(n + 1); // 第 n 列完全覆盖的情况
    std::vector<int> g(n + 1); // 第 n 列空出一格的情况

    if (n >= 1)
        f[1] = 1, g[1] = 0;
    if (n >= 2)
        f[2] = 2, g[2] = 2;
    for (int i(3); i <= n; ++i)
    {
        f[i] = f[i - 1] + f[i - 2] + g[i - 1];
        f[i] %= 10000;
        g[i] = f[i - 2] * 2 + g[i - 1];
        g[i] %= 10000;
    }
    int ans(f[n]);
    std::cout << ans << std::endl;
    return 0;
}