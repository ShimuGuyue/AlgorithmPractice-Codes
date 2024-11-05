#include <iostream>
#include <cmath>
#include <iomanip>

int main(void)
{
    double a, b, c;
    std::cin >> a >> b >> c;
    double p((a + b + c) / 2);
    double ans(sqrt(p * (p - a) * (p - b) * (p - c)));
    std::cout << std::fixed << std::setprecision(1) << ans << std::endl;
    return 0;
}