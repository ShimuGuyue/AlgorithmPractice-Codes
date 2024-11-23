#include <iostream>
#include <deque>
#include <string>

int main(void)
{
    std::string n;
    std::cin >> n;
    int k;
    std::cin >> k;
    std::deque<char> ans;
    for (char c : n)
    {
        if (ans.empty())
        {
            ans.push_back(c);
        }
        else
        {
            if (c >= ans.back())
            {
                ans.push_back(c);
            }
            else
            {
                while (!ans.empty() && ans.back() > c && k)
                {
                    ans.pop_back();
                    --k;
                }
                ans.push_back(c);
            }
        }
        while (ans.front() == '0')
        {
            ans.pop_front();
        }
    }
    while (k--)
    {
        ans.pop_back();
    }
    for (char c : ans)
    {
        std::cout << c;
    }
    if (ans.empty())
    {
        std::cout << 0;
    }
    std::cout << std::endl;
    return 0;
}