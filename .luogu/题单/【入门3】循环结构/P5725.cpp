#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;

    for (int i(0); i < n; ++i)
    {
        for (int j(1); j <= n; ++j)
        {
            int a(i * n + j);
            if (a < 10)
                std::cout << 0 << a;
            else 
                std::cout << a;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int flag(1);
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= n - i; ++j)
        {
            std::cout << "  ";
        }
        for (int j(n - i + 1); j <= n; ++j)
        {
            if (flag < 10)
                std::cout << 0 << flag++;
            else
                std::cout << flag++;
        }
        std::cout << std::endl;
    }
    return 0;
}