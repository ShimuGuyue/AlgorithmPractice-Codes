#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;
    int b(0);
    int g(0);

    for (int i(0); i < s.size() - 2; ++i)
    {
        if (s[i] == 'b' && s[i+1] == 'o' && s[i+2] == 'y')
        {
            s[i] = s[i+1] = s[i+2] = '.';
            ++b;
        }
    }
    for (int i(0); i < s.size() - 1; ++i)
    {
        if ((s[i] == 'b' && s[i+1] == 'o') || (s[i] == 'o' && s[i+1] == 'y'))
        {
            s[i] = s[i+1] = '.';
            ++b;
        }
    }
    for (int i(0); i < s.size(); ++i)
    {
        if (s[i] == 'b' || s[i] == 'o' || s[i] == 'y')
        {
            s[i] = '.';
            ++b;
        }
    }

    for (int i(0); i < s.size() - 3; ++i)
    {
        if (s[i] == 'g' && s[i+1] == 'i' && s[i+2] == 'r' && s[i+3] == 'l')
        {
            s[i] = s[i+1] = s[i+2] = s[i+3] = '.';
            ++g;
        }
    }
    for (int i(0); i < s.size() - 2; ++i)
    {
        if ((s[i] == 'g' && s[i+1] == 'i' && s[i+2] == 'r') ||(s[i] == 'i' && s[i+1] == 'r' && s[i+2] == 'l'))
        {
            s[i] = s[i+1] = s[i+2] = '.';
            ++g;
        }
    }
    for (int i(0); i < s.size() - 1; ++i)
    {
        if ((s[i] == 'g' && s[i+1] == 'i') || (s[i] == 'i' && s[i+1] == 'r') || (s[i] == 'r' && s[i+1] == 'l'))
        {
            s[i] = s[i+1] = '.';
            ++g;
        }
    }
    for (int i(0); i < s.size(); ++i)
    {
        if (s[i] == 'g' || s[i] == 'i' || s[i] == 'r' || s[i] == 'l')
        {
            s[i] = '.';
            ++g;
        }
    }

    std::cout << b << std::endl;
    std::cout << g << std::endl;
    return 0;
}