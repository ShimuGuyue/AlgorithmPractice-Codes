#include <iostream>
#include <vector>

int main(void)
{
    std::string a_s;
    std::string b_s;
    std::cin >> a_s;
    std::cin >> b_s;
    std::vector<int64_t> a;
    std::vector<int64_t> b;
    for (std::string::reverse_iterator it(a_s.rbegin()); it != a_s.rend(); ++it)
    {
        a.push_back((*it) - '0');
    }
    for (std::string::reverse_iterator it(b_s.rbegin()); it != b_s.rend(); ++it)
    {
        b.push_back((*it) - '0');
    }
    std::vector<int64_t> ans(a.size() + b.size());
    for (int i(0); i < a.size(); ++i)
    {
        for (int j(0); j < b. size(); ++j)
        {
            ans[i + j] += a[i] * b[j];
        }
    }
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
    while (ans.back() == 0 && ans.size() > 1)
    {
        ans.pop_back();
    }
    for (std::vector<int64_t>::reverse_iterator it(ans.rbegin()); it != ans.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    return 0;
}