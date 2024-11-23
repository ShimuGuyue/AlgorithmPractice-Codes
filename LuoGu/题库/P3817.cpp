#include <iostream>
#include <vector>

int main(void)
{
    int64_t n, x;
    std::cin >> n >> x;
    std::vector<int64_t> as(n);
    for (int64_t& a : as)
    {
        std::cin >> a;
    }
    int64_t ans(0);
    for (int i(1); i < n; ++i)
    {
        if (as[i-1] + as[i] <= x)
            continue;

        int64_t dif(as[i-1] + as[i] - x);
        ans += dif;
        if (as[i] >= dif)
        {
            as[i] -= dif;
        }
        else
        {
            dif -= as[i];
            as[i] = 0;
            as[i-1] -= dif;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}