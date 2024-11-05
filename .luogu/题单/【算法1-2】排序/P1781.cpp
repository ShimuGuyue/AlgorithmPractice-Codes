#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    std::string max(100, '0');
    int index;
    for (int i(1); i <= n; ++i)
    {
        std::string a;
        std::cin >> a;
        int n(100 - a.length());
        std::string b(n, '0');
        b += a;
        if (b > max)
        {
            max = b;
            index = i;
        }
    }
    std::cout << index << std::endl;
    bool out(false);
    for (char c : max)
    {
        if (out)
            std::cout << c;
        else if (c != '0')
        {
            out = true;
            std::cout << c;
        }
    }
    std::cout << std::endl;
    return 0;
}