#include <iostream>

int main(void)
{
    int flag(8);
    int ans(0);
    for (int i(1); i <= 7; ++i)
    {
        int t1, t2;
        std::cin >> t1 >> t2;
        int t(t1 + t2);
        if (t > flag)
        {
            flag = t;
            ans = i;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}