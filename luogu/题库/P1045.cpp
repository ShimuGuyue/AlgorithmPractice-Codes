#include <iostream>
#include <vector>
#include <cmath>

int main(void)
{
    int p;
    std::cin >> p;
    std::cout << ceil(log10(2) * p) << std::endl;
    std::vector<int64_t> ans(501);
    ans.front() = 1;
    while (p)
    {
        int n(ans.size() < 500 ? ans.size() : 500);
        if (p > 30)
        {
            for (int i(0); i < n; ++i)
            {
                ans[i] *= pow(2, 30);
            }
            p -= 30;
        }
        else
        {
            for (int i(0); i < n; ++i)
            {
                ans[i] *= pow(2, p);
            }
            p = 0;
        }
        for (int i(0); i < n; ++i)
        {
            if (ans[i] >= 10)
            {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }  
        }
    }
    --ans.front();
    ans.resize(500);
    for (int i(1); i <= 500; ++i)
    {
        std::cout << ans[500 - i];
        if (i % 50 == 0)
            std::cout << std::endl;
    }
    return 0;
}