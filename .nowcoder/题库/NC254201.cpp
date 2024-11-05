#include <iostream>

int main(void)
{
    std::string s;
    std::string t;
    std::cin >> s;
    std::cin >> t;
    int n(s.size());
    int m(t.size());
    int ans(0);
    for (int i(0); i < n; ++i)
    {
        bool ok(true);
        for (int j(0); j < m; ++j)
        {
            if (s[(i + j) % n] != t[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ++ans;
    }
    std::cout << ans << std::endl; 
    return 0;
}