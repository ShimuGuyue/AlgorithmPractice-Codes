#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> a(10);
    for (int& i : a)
    {
        std::cin >> i;
    }
    int l;
    std::cin >> l;
    l += 30;
    int ans(0);
    for (int i : a)
    {
        if (l >= i)
            ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}