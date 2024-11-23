#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    for (int i(n); i >= 0; --i)
    {
        int a;
        std::cin >> a;

        if (a)
        {
            if (i != n && a > 0)
            {
                std::cout << "+";
            }
            if (i == 0)
            {
                std::cout << a;
            }
            else if (i == 1)
            {
                if (a == 1)
                    std::cout << "x";
                else if (a == -1)
                    std::cout << "-" << "x";
                else if (a > 0)
                    std::cout << a << "x";
                else if (a < 0)
                    std::cout << a << "x";
            }
            else
            {
                if (a == 1)
                    std::cout << "x^" << i;
                else if (a == -1)
                    std::cout << "-" << "x^" << i;
                else if (a > 0)
                    std::cout << a << "x^" << i;
                else if (a < 0)
                    std::cout << a << "x^" << i;
            }
        }
    }
    std::cout << std::endl;
    return 0;
}