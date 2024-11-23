#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    int sum(0);
    for (int i(0); i < m; ++i)
    {
        sum += a[i];
    }
    int ans(sum);
    for (int i(m); i < n; ++i)
    {
        sum += a[i];
        sum -= a[i - m];
        ans = std::min(ans, sum);
    }
    std::cout << ans << std::endl;
    return 0;
}