#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    int ans(0);
    int len(1);
    for (int i(1); i < n; ++i)
    {
        if (a[i] == a[i - 1] + 1)
            ++len;
        else
            len = 1;
        ans = std::max(ans, len);
    }
    std::cout << ans << std::endl;
    return 0;
}