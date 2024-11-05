#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    while (n--)
    {
        int number, a, b, c;
        std::cin >> number >> a >> b;
        if (a + b > 140 && a * 7 + b * 3 >= 80 * 10)
            std::cout << "Excellent" << std::endl;
        else
            std::cout << "Not excellent" << std::endl;
    }
    return 0;
}