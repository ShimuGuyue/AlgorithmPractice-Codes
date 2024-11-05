#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> counts(10);
    counts[0] = 6; counts[1] = 2; counts[2] = 5; counts[3] = 5; counts[4] = 4;
    counts[5] = 5; counts[6] = 6; counts[7] = 3; counts[8] = 7; counts[9] = 6;
    
    int n;
    std::cin >> n;
    n -= 2 + 2;

    int ans(0);
    for (int i(0); i < 1000; ++i)
    {
        for (int j(0); j < 1000; ++j)
        {
            int count(0);
            int flag(i + j);
            if (i == 0)
                count += counts[0];
            if (j == 0)
                count += counts[0];
            if (flag == 0)
                count += counts[0];
            int ii(i), jj(j);
            while (ii)
            {
                count += counts[ii % 10];
                ii /= 10;
            }
            while (jj)
            {
                count += counts[jj % 10];
                jj /= 10;
            }
            while (flag)
            {
                count += counts[flag % 10];
                flag /= 10;
            }
            if (count == n)
                ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}