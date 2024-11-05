#include <iostream>

int main(void)
{
    int m, t, s;
    std::cin >> m >> t >> s;

    if (t == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int count(s / t);
    if (s % t)
        ++count;
    int ans(m - count);
    if (ans < 0)
        ans = 0;
    std::cout << ans << std::endl;
    return 0;
}