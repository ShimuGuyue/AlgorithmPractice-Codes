#include <iostream>
#include <vector>

int main(void)
{
    std::string s;
    std::cin >> s;
    std::vector<int> flags;
    for (char c : s)
    {
        if (isdigit(c))
            flags.push_back(c - '0');
    }
    if (s.back() == 'X')
        flags.push_back(10);
    int flag1(0);
    for (int i(0); i < flags.size() - 1; ++i)
    {
        flag1 += (i + 1) * flags[i];
    }
    flag1 %= 11;
    char flag2(flag1 == 10 ? 'X' : flag1 + '0');
    if (flag2 == s.back())
        std::cout << "Right" << std::endl;
    else
    {
        s.back() = flag2;
        std::cout << s << std::endl;
    }
    return 0;
}