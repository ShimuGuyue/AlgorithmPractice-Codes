#include <iostream>
#include <vector>
#include <algorithm>

struct Hand
{
    int l;
    int r;
};

std::vector<int> operator*(std::vector<int> &a, int b);
std::vector<int> operator/(std::vector<int> &a, int b);
bool operator>(std::vector<int> &a, std::vector<int> &b);

int main(void)
{
    int n;
    std::cin >> n;
    std::string a_s;
    int b;
    std::cin >> a_s >> b;
    std::vector<int> a;
    for (int i(1); i <= a_s.size(); ++i)
    {
        a.push_back(a_s[a_s.size() - i] - '0');
    }
    std::vector<Hand> hands(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> hands[i].l >> hands[i].r;
    }

    std::sort(hands.begin(), hands.end(),
    [](Hand a, Hand b)
    {
        //     a.l / b.r < b.l / a.r 
        if (a.l * a.r != b.l * b.r)
            return a.l * a.r < b.l * b.r;
        return a.r < b.r;
    });

    std::vector<int> ans(1, 0);
    std::vector<int> l(a);
    int r(b);
    for (int i(0); i < n; ++i)
    {
        r = hands[i].r;
        std::vector<int> sum(l / r);
        ans = ans > sum ? ans : sum;
        l = l * hands[i].l;
    }

    for (int i(1); i <= ans.size(); ++i)
    {
        std::cout << ans[ans.size() - i];
    }
    std::cout << std::endl;
    return 0;
}

// 重载 * 运算符
std::vector<int> operator*(std::vector<int> &a, int b)
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

// 重载 / 运算符
std::vector<int> operator/(std::vector<int> &a, int b)
{
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

// 重载 > 运算符
bool operator>(std::vector<int> &a, std::vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    int n(a.size());
    for (int i(n - 1); i >= 0; --i)
    {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    return false;
}