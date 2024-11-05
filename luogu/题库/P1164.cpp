// 参考教程 https://www.bilibili.com/video/BV1qh411U7QG/?spm_id_from=333.880.my_history.page.click&vd_source=fe9156abafd89942972a6860493f9a04
#include <iostream>
#include <vector>

int dp01(int n, int v, std::vector<int>& costs);

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> costs(n + 1);
    for (int i(1); i <= n; ++i)
    {
        std::cin >> costs[i];
    }
    int ans(dp01(n, m, costs));
    std::cout << ans << std::endl;
    return 0;
}

int dp01(int n, int v, std::vector<int>& costs)
{
    // v 个钱，n 个菜
    std::vector<std::vector<int>> dp(v + 1, std::vector<int>(n + 1)); 
    for (int i(0); i <= n; ++i)
    {
        dp[0][i] = 1;
    }
    for (int i(1); i <= v; ++i) // 钱
    {
        for (int j(1); j <= n; ++j) // 菜的数量
        {
            if (costs[j] > i)
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - costs[j]][j - 1];
        }
    }
    int ans(dp[v][n]);
    return ans;
}