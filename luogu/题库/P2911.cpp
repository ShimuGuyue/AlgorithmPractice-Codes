#include <iostream>
#include <map>

int main(void)
{
    int s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    std::map<int, int> counts;
    for (int i(1); i <= s1; ++i)
    {
        for (int j(1); j <= s2; ++j)
        {
            for (int k(1); k <= s3; ++k)
            {
                int sum(i + j + k);
                ++counts[sum];
            }
        }
    }
    int ans(0);
    int count(0);
    for (std::pair<int, int> ii : counts)
    {
        if (ii.second > count)
        {
            count = ii.second;
            ans = ii.first;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}