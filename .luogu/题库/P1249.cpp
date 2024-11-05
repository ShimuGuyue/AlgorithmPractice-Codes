#include <iostream>
#include <vector>
#include <map>

void operator*=(std::vector<int> &a, int b);

int main(void)
{
    int n;
    std::cin >> n;
    std::map<int, int> nums;
    int flag(2);
    while (n > 0)
    {
        n -= flag;
        if (n >= 0)
            ++nums[flag];
        else
        {
            if (n == -1)
            {
                ++nums[flag + 1];
                nums.erase(2);
            }
            else
            {
                ++nums[flag];
                nums.erase(-n);
            }
        }
        ++flag;
    }
    std::vector<int> ans(1, 1);
    for (std::pair<int, int> ii : nums)
    {
        int i(ii.first);
        ans *= i;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i(1); i <= ans.size(); ++i)
    {
        std::cout << ans[ans.size() - i];
    }
    std::cout << std::endl;
    return 0;
}

void operator*=(std::vector<int> &a, int b)
{
    // 预设答案数组大小
    std::vector<int> ans(a.size());
    // 逐位相乘
    for (int i(0); i < a.size(); ++i)
    {
        ans[i] += a[i] * b;
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
    a = ans;
}