#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(4));
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < 3; ++j)
        {
            std::cin >> a[i][j];
        }
        a[i][3] = a[i][0] + a[i][1] + a[i][2];
    }

    int ans(0);
    for (int i(0); i < n; ++i)
    {
        for (int j(i + 1); j < n; ++j)
        {
            if (abs(a[i][0] - a[j][0]) <= 5 && abs(a[i][1] - a[j][1]) <= 5 && abs(a[i][2] - a[j][2]) <= 5 && abs(a[i][3] - a[j][3]) <= 10)
                ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}