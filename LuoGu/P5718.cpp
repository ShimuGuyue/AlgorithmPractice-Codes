#include <iostream>
#include <limits.h>

int main(void)
{
    int n;
    std::cin >> n;
    int ans(INT_MAX);
    while (n--)
    {
        int a;
        std::cin >> a;
        ans = std::min(ans, a);
    }
    std::cout << ans << std::endl;
    return 0;
}