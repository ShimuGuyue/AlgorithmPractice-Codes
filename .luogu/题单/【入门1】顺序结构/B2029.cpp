#include <iostream>
#include <cmath>

const double PI(3.14);

int main(void)
{
    double h, r;
    std::cin >> h >> r;
    h /= 10;
    r /= 10;
    double v(PI * r * r * h);
    int ans(std::ceil(20 / v));
    std::cout << ans << std::endl;
    return 0;
}