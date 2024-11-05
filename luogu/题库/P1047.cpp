#include <iostream>
#include <vector>

int main(void)
{
    int l, m;
    std::cin >> l >> m;
    std::vector<int> a(l + 1, 1);
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        for (int i(u); i <= v; ++i)
        {
            a[i] = 0;
        }
    }
    int ans(0);
    for (int i : a)
    {
        ans += i;
    }
    std::cout << ans << std::endl;
    return 0;
}