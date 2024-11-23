#include <iostream>
#include <string>

int main(void)
{
    int q;
    std::cin >> q;
    std::string s;
    std::cin >> s;
    while (q--)
    {
        int mode;
        std::cin >> mode;
        if (mode == 1)
        {
            std::string str;
            std::cin >> str;
            s += str;
            std::cout << s << std::endl;
        }
        else if (mode == 2)
        {
            int a, b;
            std::cin >> a >> b;
            std::string temp(s.begin() + a, s.begin() + a + b);
            s = temp;
            std::cout << s << std::endl;
        }
        else if (mode == 3)
        {
            int a;
            std::string str;
            std::cin >> a >> str;
            s.insert(a, str);
            std::cout << s << std::endl;
        }
        else if (mode == 4)
        {
            std::string str;
            std::cin >> str;
            if (s.find(str) != std::string::npos)
                std::cout << s.find(str) << std::endl;
            else
                std::cout << -1 << std::endl;
        }
    }
    return 0;
}