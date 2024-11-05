#include <iostream>

int main(void)
{
    std::string n;
    std::cin >> n;

    if (n == "0")
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    bool out(false);
    if (n.front() == '-')
        std::cout << "-";
    for (std::string::reverse_iterator it(n.rbegin()); it != n.rend(); ++it)
    {
        if (out)
        {
            if (*it != '-')
            {
                std::cout << *it;
            }
        }
        else
        {
            if (*it != '0')
            {
                out = true;
                std::cout << *it;
            }
        }
    }
    std::cout << std::endl;
    return 0;
}