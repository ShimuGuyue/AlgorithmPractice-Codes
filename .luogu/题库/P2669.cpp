#include <iostream>

int main(void)
{
    int k;
    std::cin >> k;
    int ans(0);
    int flag(1);
    while (k)
    {
        if (k >= flag)
        {
            ans += flag * flag;
            k -= flag;
        }
        else
        {
            ans += flag * k;
            break;
        }
        ++flag;
    }
    std::cout << ans << std::endl;
    return 0;
}