#include <iostream>

int main(void)
{
    int sum1(0);
    int sum2(0);
    for (int x(1); x <= 12; ++x)
    {
        int money;
        std::cin >> money;

        if (sum1 + 300 < money)
        {
            std::cout << -x << std::endl;
            return;
        }

        sum1 = sum1 + 300 - money;
        sum2 += sum1 / 100 * 100;
        sum2 %= 100;
    }
    std::cout << sum1 + sum2 * 1.2 << std::endl;
    return 0;
}