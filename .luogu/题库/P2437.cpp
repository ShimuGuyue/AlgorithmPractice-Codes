#include <iostream>
#include <vector>

std::vector<int> operator+(std::vector<int>& a, std::vector<int>& b);

int main(void)
{
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> dp(n + 1);
    if (m + 1 <= n)
        dp[m + 1] = std::vector<int>(1, 1);
    if (m + 2 <= n)
        dp[m + 2] = std::vector<int>(1, 2);
    for (int i(m + 3); i <= n; ++i)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }    
    std::vector<int> ans(dp[n]);
    for (int i(1); i <= ans.size(); ++i)
    {
        std::cout << ans[ans.size() - i];
    }
    std::cout << std::endl;
    return 0;
}

// 重载 + 运算符
std::vector<int> operator+(std::vector<int>& a, std::vector<int>& b)
{
    // 预设答案数组大小
    int n(std::max(a.size(), b.size()));
    std::vector<int> ans(n);
    a.resize(n);
    b.resize(n);
    // 逐位相加
    for (int i(0); i < n; ++i)
    {
        ans[i] = a[i] + b[i];
    }
    // 逐位进位
    for (int i(0); i < n; ++i)
    {
        if (ans[i] >= 10)
        {
            if (i != n - 1)
                ++ans[i + 1];
            else
                ans.push_back(1);
            ans[i] %= 10;
        }
    }
    return ans;
}