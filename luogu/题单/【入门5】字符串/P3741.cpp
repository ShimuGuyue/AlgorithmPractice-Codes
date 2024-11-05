#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans(0);
    for (int i(1); i < n; ++i)
    {
        if (s[i - 1] == 'V' && s[i] == 'K')
        {
            ++ans;
            s[i - 1] = '.';
            s[i] = '.';
        }
    }
    for (int i(1); i < n; ++i)
    {
        if (s[i - 1] == 'V' && s[i] == 'V')
        {
            ++ans;
            break;
        }
        if (s[i - 1] == 'K' && s[i] == 'K')
        {
            ++ans;
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}