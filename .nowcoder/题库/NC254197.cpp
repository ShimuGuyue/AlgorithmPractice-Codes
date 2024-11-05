#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int64_t& a : as)
    {
        std::cin >> a;
    }
    std::string colors;
    std::cin >> colors;

    std::vector<int64_t> dp(n);
    for (int i(1); i < n; ++i)
    {
        dp[i] = dp[i-1];
        if (colors[i] != colors[i-1])
        {
            if (i == 1)
                dp[i] = as[i] + as[i-1];
            else
                dp[i] = std::max(dp[i - 2] + as[i] + as[i-1], dp[i]);
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}