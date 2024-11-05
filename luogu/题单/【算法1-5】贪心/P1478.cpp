#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, s;
    std::cin >> n >> s;
    int a, b;
    std::cin >> a >> b;
    std::vector<int> energys;
    for (int i(0); i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        if (x > a + b)
            continue;
        energys.push_back(y);
    }

    std::sort(energys.begin(), energys.end());

    int ans(0);
    for (int y : energys)
    {
        if (s < y)
            break;
        ++ans;
        s -= y;
    }
    std::cout << ans << std::endl;

    return 0;
}