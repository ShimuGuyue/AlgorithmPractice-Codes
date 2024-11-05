#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end(),
        [](int a, int b)
        {
            return a > b;
        });
    int ans(0);
    for (int k(0); k < n - 2; ++k)
    {
        for (int j(k + 1); j < n - 1; ++j)
        {
            bool find(false);
            for (int i(j + 1); i < n; ++i)
            {
                if (a[k] == a[i] + a[j])
                {
                    ++ans;
                    find = true;
                    break;
                }
            }
            if (find)
                break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}