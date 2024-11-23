#include <iostream>
#include <iomanip>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    double ans(0);
    for (int i(0); i < n; ++i)
    {
        double max(0), min(10);
        double grade(0);
        for (int j(0); j < m; ++j)
        {
            double a;
            std::cin >> a;
            max = std::max(max, a);
            min = std::min(min, a);
            grade += a;
        }
        grade -= max + min;
        grade /= m - 2;
        ans = std::max(ans, grade);
    }
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}