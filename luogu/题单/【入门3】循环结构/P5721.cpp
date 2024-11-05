#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int flag(1);
    for (int i(n); i > 0; --i)
    {
        for (int j(i); j > 0; --j)
        {
            if (flag < 10)
                std::cout << 0 << flag;
            else
                std::cout << flag;
            ++flag;
        }
        std::cout << std::endl;
    }
    return 0;
}