#include <iostream>

int main(void)
{
    int n, x;
    std::cin >> n >> x;
    int ans(0);
    for (int i(1); i <= n; ++i)
    {
        int j(i);
        while (j)
        {
            if (j % 10 == x)
                ++ans;
            j /= 10;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}