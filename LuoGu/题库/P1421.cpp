#include <iostream>

const int per(1 * 10 + 9);

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int sum(a * 10 + b);
    int ans(sum / per);
    std::cout << ans << std::endl;
    return 0;
}