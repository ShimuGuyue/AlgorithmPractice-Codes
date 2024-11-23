#include <iostream>

int main(void)
{
    int n, k;
    std::cin >> n >> k;
    int cnt(1);
    int max(0);
    for (int i(1); cnt < k; i += 2, ++cnt)
    {
        std::cout << i + 1 << " ";
        std::cout << i << " ";
        max = i + 1;
    }
    for (int i(n); i > max; --i)
    {
        std::cout << i << " ";
    }
    return 0;
}