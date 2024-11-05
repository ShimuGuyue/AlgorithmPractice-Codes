#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;

    if (n < 10 || n > 30)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int ans(0);
    std::vector<std::vector<int>> flags;
    for (int a(1); a <= 3; ++a)
    for (int b(1); b <= 3; ++b)
    for (int c(1); c <= 3; ++c)
    for (int d(1); d <= 3; ++d)
    for (int e(1); e <= 3; ++e)
    for (int f(1); f <= 3; ++f)
    for (int g(1); g <= 3; ++g)
    for (int h(1); h <= 3; ++h)
    for (int i(1); i <= 3; ++i)
    for (int j(1); j <= 3; ++j)
        if (a + b + c + d + e + f + g + h + i + j == n)
        {
            ++ans;
            std::vector<int> temp(10);
            temp[0] = a; temp[1] = b; temp[2] = c; temp[3] = d; temp[4] = e;
            temp[5] = f; temp[6] = g; temp[7] = h; temp[8] = i; temp[9] = j;
            flags.push_back(temp);
        }
    std::cout << ans << std::endl;
    for (std::vector<int> vi : flags)
    {
        for (int i : vi)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}