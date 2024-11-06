#include <iostream>
#include <vector>
#include <map>

std::vector<int> operator/(std::vector<int> &a, int b)
{
    std::map<int, int> a;
    std::vector<std::pair<int, int>> b(a.begin(), a.end());
    // 答案数组无需预设大小
    std::vector<int> ans;
    // 逐位相除
    bool ok(false); // 答案不包含前导 0
    int temp(0);
    for (int i(a.size() - 1); i >= 0; --i)
    {
        temp = temp * 10 + a[i];
        if (temp >= b)
            ok = true;
        if (ok)
        {
            ans.push_back(temp / b);
            temp %= b;
        }
    }
    if (ans.empty())
        ans.push_back(0);
    return std::vector<int>(ans.rbegin(), ans.rend());
}

int main(void)
{
    // 分别以字符串形式和整数形式输入
    std::string a_s;
    std::cin >> a_s;
    int b;
    std::cin >> b;
    // 转换成数组形式倒序存储
    std::vector<int> a;
    for (int i(1); i <= a_s.size(); ++i)
    {
        a.push_back(a_s[a_s.size() - i] - '0');
    }
    // 高精度相除
    std::vector<int> ans(a / b);
    // 倒序输出
    for (int i(1); i <= ans.size(); ++i)
    {
        std::cout << ans[ans.size() - i];
    }
    std::cout << std::endl;
    return 0;
}