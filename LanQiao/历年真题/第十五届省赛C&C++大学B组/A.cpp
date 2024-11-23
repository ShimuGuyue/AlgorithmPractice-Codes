#include <iostream>

int main(void)
{
    int n(50), m(7);
    int ans(n * (n - 1) / 2 - m * (m - 1) / 2);
    std::cout << ans << std::endl;
    return 0;
}