#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> as(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i];
    }
    while (m--)
    {
        int q;
        std::cin >> q;
        std::cout << as[q - 1] << std::endl;
    }
    return 0;
}