#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;
    double ans(0);
    ans += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    ans += sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    ans += sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}