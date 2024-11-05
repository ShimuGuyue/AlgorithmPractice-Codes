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
    int ans(0);
    for (int i(0); i < n; ++i)
    {
        int min(a[i]);
        int index(i);
        for (int j(i); j < n; ++j)
        {
            if (a[j] < min)
            {
                min = a[j];
                index = j;
            }
        }
        for (int j(index); j > i; --j)
        {
            std::swap(a[j - 1], a[j]);
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}