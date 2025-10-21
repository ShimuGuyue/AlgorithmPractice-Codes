#include <iostream>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    int64_t square(0);
    int64_t rectangle(0);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < m; ++j)
        {
            rectangle += (n - i) * (m - j);
            square += std::min(n - i, m - j);
            rectangle -= std::min(n - i, m - j);
        }
    }
    std::cout << square << " " << rectangle << std::endl;
    return 0;
}