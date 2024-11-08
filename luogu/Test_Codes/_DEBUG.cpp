#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> a[i];
    }
    int64_t ans(0);
    for (int i(0); i < n; ++i)
    {
        std::map<int, int> cnt;
        for (int j(i); j < n; ++j)
        {
            ++cnt[a[j]];
            ans += cnt.size();
        }
    }
    std::cout << ans << std::endl;
    return 0;
}