#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    n /= 52;
    for (int k(1); ; ++k)
    {
        int temp(n);
        temp -= 21 * k;
        if (temp % 7 == 0 && temp / 7 <= 100)
        {
            int x(temp / 7);
            std::cout << x << std::endl;
            std::cout << k << std::endl;
            break;
        }
    }
    return 0;
}

/*
    x + x + k + x + k * 2 + x + k * 3 + x + k * 4 + x + k * 5 + x + k * 6 == n
    7 * x + 21 * k == n;
*/