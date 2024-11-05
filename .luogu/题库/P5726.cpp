#include <iostream>
#include <iomanip>

int main(void)
{
    int n;
    std::cin >> n;
    double sum(0);
    double max(0);
    double min(10);
    for (int i(0); i < n; ++i)
    {
        double a;
        std::cin >> a;
        sum += a;
        max = std::max(max, a);
        min = std::min(min, a);
    }
    double ans((sum - max - min) / (n - 2));
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}