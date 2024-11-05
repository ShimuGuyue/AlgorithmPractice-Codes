#include <iostream>
#include <vector>

int dp01(int n, int v, std::vector<int> costs, std::vector<int> values);

int main(void)
{
    const int n(4);
    std::vector<std::vector<int>> works(n);
    for (int i(0); i < n; ++i)
    {
        int s;
        std::cin >> s;
        works[i].resize(s + 1);
    }
    int ans(0);
    for (int i(0); i < n; ++i)
    {
        int sum(0);
        int m(works[i].size() - 1);
        for (int j(1); j <= m; ++j)
        {
            std::cin >> works[i][j];
            sum += works[i][j];
        }
        int min(dp01(m, (sum + 1) / 2, works[i], works[i]));
        min = std::max(min, sum - min);
        ans += min;
    }
    std::cout << ans << std::endl;
    return 0;
}

int dp01(int n, int v, std::vector<int> costs, std::vector<int> values)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(v + 1));
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= v; ++j)
        {
            if (j >= costs[i])
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - costs[i]] + values[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][v];
}