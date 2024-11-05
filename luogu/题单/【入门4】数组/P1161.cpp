#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<double> a(n);
    std::vector<int> t(n);
    int max(0);
    for (int i(0); i < n; ++i)
    {
        std::cin >> a[i] >> t[i];
        int len(a[i] * t[i]);
        max = std::max(max, len);
    }
    std::vector<int> lights(max + 1);
    for (int i(0); i < n; ++i)
    {
        for (int j(1); j <= t[i]; ++j)
        {
            int index(a[i] * j);
            lights[index] = (lights[index] + 1) % 2;
        }
    }
    for (int i(1); i <= max; ++i)
    {
        if (lights[i])
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    return 0;
}