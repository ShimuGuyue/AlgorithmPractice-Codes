#include <iostream>
#include <vector>

const int64_t mod(1e9+7);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(5010);
    int64_t min(100000);
    int64_t max(0);
    while (n--)
    {
        int64_t a;
        std::cin >> a;
        ++as[a];
        min = std::min(min, a);
        max = std::max(max, a);
    }

    int64_t ans(0);
    for (int i(min); i <= max; ++i)
    {
        if (as[i] < 2)
            continue;
        for (int j(min); j * 2 <= i; ++j)
        {
            if (as[j] == 0)
                continue;
            if (j * 2 == i)
            {
                ans += (as[i] * (as[i] - 1) / 2) * (as[j] * (as[j] - 1) / 2);
                ans %= mod;  
            }
            else
            {
                int k(i - j);
                if (as[k] == 0)
                    continue;
                ans += (as[i] * (as[i] - 1) / 2) * as[j] * as[k];
                ans %= mod;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}