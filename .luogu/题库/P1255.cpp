#include <iostream>
#include <vector>

std::vector<int> operator+(std::vector<int>& a, std::vector<int>& b);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> anss(n + 1);
    if (n >= 1)
        anss[1] = std::vector<int>(1, 1);
    if (n >= 2)
        anss[2] = std::vector<int>(1, 2);
    for (int i(3); i <= n; ++i)
    {
        anss[i] = anss[i - 1] + anss[i - 2];
    }
    for (int i(1); i <= anss[n].size(); ++i)
    {
        std::cout << anss[n][anss[n].size() - i];
    }
    std::cout << std::endl;
    return 0;
}

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