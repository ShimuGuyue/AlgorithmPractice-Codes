#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    for (int i(0); i < n; ++i)
    {
        int smaller(0);
        for (int j(0); j < i; ++j)
        {
            if (a[j] < a[i])
                ++smaller;
        }
        std::cout << smaller << " ";
    }
    std::cout << std::endl;
    return 0;
}