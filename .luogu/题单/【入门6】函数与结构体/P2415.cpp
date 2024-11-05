#include <iostream>
#include <cmath>

int main(void)
{
    int64_t n(0);
    int64_t ans(0);
    int64_t a;
    while (std::cin >> a)
    {
        ++n;
        ans += a;
    }
    ans *= pow(2, n - 1);
    std::cout << ans << std::endl;
    return 0;
}