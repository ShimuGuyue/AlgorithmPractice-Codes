#include <iostream>

int main(void)
{
    int k;
    std::cin >> k;
    double sum(0);
    double n(0);
    while (sum <= k)
    {
        ++n;
        sum += 1 / n;
    }
    std::cout << n << std::endl;
    return 0;
}