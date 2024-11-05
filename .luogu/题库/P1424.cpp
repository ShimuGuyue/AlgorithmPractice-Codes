#include <iostream>

int main(void)
{
    int x, n;
    std::cin >> x >> n;
    int day(std::max(5 - x + 1, 0));
    n -= 7 - x + 1;
    day += n / 7 * 5;
    day += n % 7 <= 5 ? n % 7 : 5;
    int ans(day * 250);
    std::cout << ans << std::endl;
    return 0;
}