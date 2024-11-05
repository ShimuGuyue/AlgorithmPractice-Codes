#include <iostream>

int main(void)
{
    int p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;
    std::string s;
    std::cin >> s;
    int n(s.size());
    for (int i(0); i < n; ++i)
    {
        if (s[i] == '-')
            if (i == 0 || i == n - 1)
                std::cout << s[i];
            else if ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (isalpha(s[i - 1]) && isalpha(s[i + 1])))
                if (s[i - 1] >= s[i + 1])
                    std::cout << s[i];
                else
                    if (isdigit(s[i - 1]))
                        if (p3 == 1)
                            for (char c(s[i - 1] + 1); c < s[i + 1]; ++c)
                            {
                                for (int j(0); j < p2; ++j)
                                {
                                    if (p1 == 3)
                                        std::cout << "*";
                                    else
                                        std::cout << c;
                                }
                            }
                        else // p3 == 2
                            for (char c(s[i + 1] - 1); c > s[i - 1]; --c)
                            {
                                for (int j(0); j < p2; ++j)
                                {
                                    if (p1 == 3)
                                        std::cout << "*";
                                    else
                                        std::cout << c;
                                }
                            }
                    else // isalpha(s[i - 1])
                        if (p3 == 1)
                            for (char c(s[i - 1] + 1); c < s[i + 1]; ++c)
                            {
                                for (int j(0); j < p2; ++j)
                                {
                                    if (p1 == 1)  
                                        std::cout << c;
                                    else if (p1 == 2)
                                        std::cout << static_cast<char>(toupper(c));
                                    else // (p1 == 3)
                                        std::cout << "*";
                                }
                            }
                        else // p3 == 2
                            for (char c(s[i + 1] - 1); c > s[i - 1]; --c)
                            {
                                for (int j(0); j < p2; ++j)
                                {
                                    if (p1 == 1)  
                                        std::cout << c;
                                    else if (p1 == 2)
                                        std::cout << static_cast<char>(toupper(c));
                                    else // (p1 == 3)
                                        std::cout << "*";
                                }
                            }
            else
                std::cout << s[i];
        else
            std::cout << s[i];
    } 
    std::cout << std::endl;
    return 0;
}