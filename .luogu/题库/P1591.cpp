#include <iostream>
#include <vector>

void solve(void);

int main(void)
{
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve(void)
{
    int n, a;
    std::cin >> n >> a;
    std::vector<int> flag(1, n);
    while (--n)
    {
        // 预设答案数组大小
        std::vector<int> ans(flag.size());
        // 逐位相乘
        for (int i(0); i < flag.size(); ++i)
        {
            ans[i] += flag[i] * n;
        }
        // 逐位相加
        for (int i(0); i < ans.size(); ++i)
        {
            if (ans[i] >= 10)
            {
                if (i != ans.size() - 1)
                    ans[i + 1] += ans[i] / 10;
                else
                    ans.push_back(ans[i] / 10);
                ans[i] %= 10;
            }
        }
        flag = ans;
    }
    int ans(0);
    for (int i : flag)
    {
        if (i == a)
            ++ans;
    }
    std::cout << ans << std::endl;
}