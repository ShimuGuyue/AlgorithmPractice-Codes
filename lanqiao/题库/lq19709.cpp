#include <iostream>
#include <string>

int main(void)
{
    int n;
    std::cin >> n;
    int ans(0);
    for (int i(1); i <= n; ++i)
    {
        std::string x(std::to_string(i));
        bool yes(true);
        for (int j(1); j <= x.size(); ++j)
        {
            if (j % 2 != x[x.size() - j] % 2)
            {
                yes = false;
                break;
            }
        }
        if (yes)
            ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}