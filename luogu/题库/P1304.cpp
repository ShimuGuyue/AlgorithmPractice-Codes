#include <iostream>

bool is_prime(int x);

int main(void)
{
    int n;
    std::cin >> n;
    for (int x(4); x <= n; x += 2)
    {
        for (int i(2); i + i <= x; ++i)
        {
            if (is_prime(i) && is_prime(x - i))
            {
                std::cout << x << "=" << i << "+" << x - i << std::endl;
                break;
            }
        }
    }
    return 0;
}

bool is_prime(int x)
{
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}