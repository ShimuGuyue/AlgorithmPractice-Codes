#include <iostream>

int64_t C(int64_t n, int64_t m);
int64_t Catalan(int64_t n);

int main(void)
{
    int64_t n;
    std::cin >> n;
    int64_t ans(Catalan(n));
    std::cout << ans << std::endl;
    return 0;
}

int64_t Catalan(int64_t n)
{
    return C(2 * n, n) / (n + 1);
}

int64_t C(int64_t n, int64_t m)
{
    int64_t ans(1);
    for(int64_t i(1);i <= m; ++i)
    {
        // 注意一定要先乘再除
        ans *= n - m + i;
        ans /= i;
    }
    return ans;
}
