#include <iostream>
#include <string>

int main(void)
{
    int i;
    std::cin >> i;
    std::cin.get();
    char ch;
    while (i--)
    {
        std::string s;
        std::getline(std::cin, s);

        if (s.front() == 'a')
        {
            ch = 'a';
            std::string sA;
            std::string sB;
            int flag(0);
            for (char c : s)
            {
                if (c == ' ')
                {
                    ++flag;
                    continue;
                }
                if (flag == 1)
                    sA += c;
                else if (flag == 2)
                    sB += c;
            }
            int a(std::stoi(sA));
            int b(std::stoi(sB));
            int ans(a + b);
            std::cout << a << "+" << b << "=" << ans << std::endl;
            std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
        }
        else if (s.front() == 'b')
        {
            ch = 'b';
            std::string sA;
            std::string sB;
            int flag(0);
            for (char c : s)
            {
                if (c == ' ')
                {
                    ++flag;
                    continue;
                }
                if (flag == 1)
                    sA += c;
                else if (flag == 2)
                    sB += c;
            }
            int a(std::stoi(sA));
            int b(std::stoi(sB));
            int ans(a - b);
            std::cout << a << "-" << b << "=" << ans << std::endl;
            std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
        }
        else if (s.front() == 'c')
        {
            ch = 'c';
            std::string sA;
            std::string sB;
            int flag(0);
            for (char c : s)
            {
                if (c == ' ')
                {
                    ++flag;
                    continue;
                }
                if (flag == 1)
                    sA += c;
                else if (flag == 2)
                    sB += c;
            }
            int a(std::stoi(sA));
            int b(std::stoi(sB));
            int ans(a * b);
            std::cout << a << "*" << b << "=" << ans << std::endl;
            std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
        }
        else
        {
            std::string sA;
            std::string sB;
            int flag(0);
            for (char c : s)
            {
                if (c == ' ')
                {
                    ++flag;
                    continue;
                }
                if (flag == 0)
                    sA += c;
                else if (flag == 1)
                    sB += c;
            }
            int a(std::stoi(sA));
            int b(std::stoi(sB));
            if (ch == 'a')
            {
                int ans(a + b);
                std::cout << a << "+" << b << "=" << ans << std::endl;
                std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
            }
            else if (ch == 'b')
            {
                int ans(a - b);
                std::cout << a << "-" << b << "=" << ans << std::endl;
                std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
            }
            else if (ch == 'c')
            {
                {
                int ans(a * b);
                std::cout << a << "*" << b << "=" << ans << std::endl;
                std::cout << sA.size() + sB.size() + std::to_string(ans).size() + 2 << std::endl;
            }
            }
        }
    }
    return 0;
}