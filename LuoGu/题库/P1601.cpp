#include <iostream>
#include <vector>

int main(void)
{
    std::string a_s;
    std::string b_s;
    std::cin >> a_s;
    std::cin >> b_s;
    std::vector<int> a;
    std::vector<int> b;
    for (std::string::reverse_iterator it(a_s.rbegin()); it != a_s.rend(); ++it)
    {
        a.push_back((*it) - '0');
    }
    for (std::string::reverse_iterator it(b_s.rbegin()); it != b_s.rend(); ++it)
    {
        b.push_back((*it) - '0');
    }

    if (a.size() <= b.size())
    {
        for (int i(0); i < a.size(); ++i)
        {
            b[i] += a[i];
        }
        for (int i(0); i < b.size(); ++i)
        {
            if (b[i] >= 10)
            {
                b[i] %= 10;
                if (i != b.size() - 1)
                    ++b[i + 1];
                else
                    b.push_back(1);
            }
        }
        for (std::vector<int>::reverse_iterator it(b.rbegin()); it != b.rend(); ++it)
        {
            std::cout << *it;
        }
        std::cout << std::endl;
    }
    else // b.size() < a.size()
    {
        for (int i(0); i < b.size(); ++i)
        {
            a[i] += b[i];
        }
        for (int i(0); i < a.size(); ++i)
        {
            if (a[i] >= 10)
            {
                a[i] %= 10;
                if (i != a.size() - 1)
                    ++a[i + 1];
                else
                    a.push_back(1);
            }
        }
        for (std::vector<int>::reverse_iterator it(a.rbegin()); it != a.rend(); ++it)
        {
            std::cout << *it;
        }
        std::cout << std::endl;
    }
    return 0;
}