#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;
    int n(s.size());
    for (int i(1); i < n; ++i)
    {
        std::string temp;
        std::cin >> temp;
        s += temp;
    }
    std::cout << n << " ";
    if (s.front() == '1')
        std::cout << 0 << " ";
    int len(1);
    for (int i(1); i < s.size(); ++i)
    {
        if (s[i - 1] == s[i])
            ++len;
        else
        {
            std::cout << len << " ";
            len = 1;
        }
    }
    std::cout << len << std::endl;
    return 0;
}