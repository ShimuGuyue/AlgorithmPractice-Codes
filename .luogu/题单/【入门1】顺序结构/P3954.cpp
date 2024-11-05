#include <iostream>

int main(void)
{
    double a, b, c;
    std::cin >> a >> b >> c;
    double ans(a * 0.20 + b * 0.30 + c * 0.50);
    std::cout << ans << std::endl;
    return 0;
}