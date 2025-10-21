#include <iostream>
#include <limits.h>

int main(void)
{
    int n;
    std::cin >> n;
    int ans(INT_MAX);
    for (int i(0); i < 3; ++i)
    {
        int cnt, per;
        std::cin >> cnt >> per;
        int buy(n % cnt ? n / cnt + 1 : n / cnt);
        ans = std::min(ans, buy * per);
    }
    std::cout << ans << std::endl;
    return 0;
}