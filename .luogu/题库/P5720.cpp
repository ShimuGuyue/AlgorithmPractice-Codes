#include <iostream>

int main(void)
{
    int a;
    std::cin >> a;
    int ans(1);
    while (a > 1)
    {
        a /= 2;
        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}