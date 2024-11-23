#include <iostream>

int main(void)
{
    int a(0), b(0), c(0);
    std::string s;
    std::cin >> s;
    for (int i(0); i * 5 < s.size(); ++i)
    {
        if (s[i * 5 + 0] == 'a')
            if (s[i * 5 + 3] == 'a')
                a = a;
            else if (s[i * 5 + 3] == 'b')
                a = b;
            else if (s[i * 5 + 3] == 'c')
                a = c;
            else
                a = s[i * 5 + 3] - '0';
        else if (s[i * 5 + 0] == 'b')
            if (s[i * 5 + 3] == 'a')
                b = a;
            else if (s[i * 5 + 3] == 'b')
                b = b;
            else if (s[i * 5 + 3] == 'c')
                b = c;
            else
                b = s[i * 5 + 3] - '0';
        else if (s[i * 5 + 0] == 'c')
            if (s[i * 5 + 3] == 'a')
                c = a;
            else if (s[i * 5 + 3] == 'b')
                c = b;
            else if (s[i * 5 + 3] == 'c')
                c = c;
            else
                c = s[i * 5 + 3] - '0';
    }
    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}