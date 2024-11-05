#include <iostream>
#include <vector>

void solve(void);

int main(void)
{
    int t(1);
    // std::cin >> t;
    while (t--)
    {
        solve();
        // std::cout << std::endl;
    }
    return 0;
}

void solve(void)
{
    std::string s;
    std::cin >> s;
    int count0(0);
    int count1(0);
    for (char c : s)
    {
        if (c == '0')
            ++count0;
        else // if (c == '1')
            ++count1;
    }
    int64_t ans(0);
    if (count1 > count0)
    {
        std::vector<int> index0;
        std::vector<int> index1;
        for (int i(0); i < s.size(); ++i)
        {
            if (s[i] == '0' && i % 2 == 0)
                index0.push_back(i);
            else if (s[i] == '1' && i % 2 == 1)
                index1.push_back(i);
        }
        for (int i(0); i < index0.size(); ++i)
        {
            ans += abs(index0[i] - index1[i]);
        }
    }
    else if (count0 > count1)
    {
        std::vector<int> index0;
        std::vector<int> index1;
        for (int i(0); i < s.size(); ++i)
        {
            if (s[i] == '0' && i % 2 == 1)
                index0.push_back(i);
            else if (s[i] == '1' && i % 2 == 0)
                index1.push_back(i);
        }
        for (int i(0); i < index0.size(); ++i)
        {
            ans += abs(index0[i] - index1[i]);
        }
    }
    else // if (count0 == count1)
    {
        int64_t ans1(0);
        int64_t ans2(0);
        {
            std::vector<int> index0;
            std::vector<int> index1;
            for (int i(0); i < s.size(); ++i)
            {
                if (s[i] == '0' && i % 2 == 0)
                    index0.push_back(i);
                else if (s[i] == '1' && i % 2 == 1)
                    index1.push_back(i);
            }
            for (int i(0); i < index0.size(); ++i)
            {
                ans1 += abs(index0[i] - index1[i]);
            }
        }
        {
            std::vector<int> index0;
            std::vector<int> index1;
            for (int i(0); i < s.size(); ++i)
            {
                if (s[i] == '0' && i % 2 == 1)
                    index0.push_back(i);
                else if (s[i] == '1' && i % 2 == 0)
                    index1.push_back(i);
            }
            for (int i(0); i < index0.size(); ++i)
            {
                ans2 += abs(index0[i] - index1[i]);
            }
        }
        ans = std::min(ans1, ans2);
    }
    std::cout << ans << std::endl;
}