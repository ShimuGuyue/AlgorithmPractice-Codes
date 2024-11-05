#include <iostream>
#include <cmath>

int gcd(int a, int b);

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a > b)
        std::swap(a, b);
    if (a > c)
        std::swap(a, c);
    if (b > c)
        std::swap(b, c);

    int gcd_(gcd(a, c));
    int sin(a / gcd_);
    int flag(c / gcd_);

    std::cout << sin << "/" << flag << std::endl;

    return 0;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}