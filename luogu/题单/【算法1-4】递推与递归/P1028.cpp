#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1, 1);
    for (int i(2); i <= n; ++i)
    {
        for (int j(1); j <= i / 2; ++j)
        {
            dp[i] += dp[j];
        }
    }
    int ans(dp[n]);
    std::cout << ans << std::endl;
    return 0;
}