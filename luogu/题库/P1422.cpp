#include <iostream>
#include <iomanip>

int main(void)
{
    double n;
    std::cin >> n;
    double ans(0);
    if (n <= 150)
        ans = n * 0.4463;
    else if (n <= 400)
        ans = 150 * 0.4463 + (n - 150) * 0.4663;
    else
        ans = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
    std::cout << std::fixed << std::setprecision(1) << ans << std::endl;
    return 0;
}