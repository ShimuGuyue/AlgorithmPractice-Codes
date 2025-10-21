#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int w;
    std::cin >> w;
    int n;
    std::cin >> n;
    std::vector<int> ps(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> ps[i];
    }

    std::sort(ps.rbegin(), ps.rend());
    int ans(0);
    int i(0), j(n-1);
    while (i < j)
    {
        if (ps[i] + ps[j] > w)
        {
            ++i;
        }
        else
        {
            ++i; --j;
        }
        ++ans;
    }
    if (i == j)
        ++ans;
    std::cout << ans << std::endl;
    return 0;
}