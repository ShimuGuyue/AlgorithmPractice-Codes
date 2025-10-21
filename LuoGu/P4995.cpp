#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin >> n;
    n += 1;
    std::vector<int> hs(n);
    hs[0] = 0;
    for (int i(1); i < n; ++i)
    {
        std::cin >> hs[i];
    }
    std::sort(hs.begin(), hs.end());

    int64_t ans(0);
    int i(0), j(n-1);
    int mode(1); // 1 -> i++ | 2 -> j--
    while (i < j)
    {
        ans += (hs[i] - hs[j]) * (hs[i] - hs[j]);
        if (mode == 1)
        {
            ++i;
            mode = 2;
        }
        else
        {
            --j;
            mode = 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}