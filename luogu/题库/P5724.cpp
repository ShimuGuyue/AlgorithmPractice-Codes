#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int max(0);
    int min(1000);
    while (n--)
    {
        int a;
        std::cin >> a;
        max = std::max(max, a);
        min = std::min(min, a);
    }
    int ans(max - min);
    std::cout << ans << std::endl;
    return 0;
}