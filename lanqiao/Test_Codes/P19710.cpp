#include <iostream>
#include <vector>

std::vector<int> operator*(std::vector<int>& a, int b);

int main(void)
{
    int n;
    std::string d_s;
    std::cin >> n >> d_s;
    int dot(d_s.find('.'));
    // 转换成数组形式倒序存储
    std::vector<int> d;
    for (int i(1); i <= d_s.size(); ++i)
    {
        if (d_s[d_s.size() - i] == '.')
            continue;
        d.push_back(d_s[d_s.size() - i] - '0');
    }
    while (n--)
    {
        d = d * 2;
    }
    // 倒序输出
    std::string ans;
    for (int i(1); i <= d.size(); ++i)
    {
        if (i - 1 == dot)
            ans += '.';
        ans += d[d.size() - i] + '0';
    }
    for (int i(0); i < ans.size(); ++i)
    {
        if (ans[i + 1] == '.')
        {
            
            break;
        }
        std::cout << ans[i];
    }
    return 0;
}

// 重载 * 运算符
std::vector<int> operator*(std::vector<int>& a, int b)
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
    return ans;
}