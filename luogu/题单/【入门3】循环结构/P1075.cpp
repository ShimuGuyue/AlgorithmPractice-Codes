#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int p;
    for (int i(2); i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            p = n / i;
            break;
        }
    }
    std::cout << p << std::endl;
    return 0;
}