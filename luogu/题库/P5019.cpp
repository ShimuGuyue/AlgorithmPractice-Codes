#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> ds(n + 1);
    for (int i(0); i < n; ++i)
    {
        std::cin >> ds[i];
    }

    int ans(0);
    while (1)
    {
        bool ok(true);
        int min(10000);
        int begin(0);
        for (int i(0); i <= n; ++i)
        {
            if (ds[i] == 0)
            {
                int last(i);
                if (begin != last)
                    ans += min;
                for (int j(begin); j < last; ++j)
                {
                    ds[j] -= min;
                }
                begin = i + 1;
                min = 10000;
            }
            else
            {
                ok = false;
                min = std::min(min, ds[i]);
            }
        } 

        if (ok)
            break;
    }
    
    std::cout << ans << std::endl;
    return 0;
}