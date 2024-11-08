#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    int64_t n(343720 * 2), m(233333 * 2);
    int64_t x(15), y(17);
    int64_t t(1);
    while (t)
    {
        if (x * t % n == 0 && y * t % m == 0)
            break;
        t++;
    }
    double ans(sqrt(x * t * x * t + y * t * y * t));
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}