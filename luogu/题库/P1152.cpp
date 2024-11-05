#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    std::map<int, int> difs;
    for (int i(1); i < n; ++i)
    {
        ++difs[abs(a[i] - a[i - 1])];
    }
    for (int i(1); i < n; ++i)
    {
        if (!difs[i])
        {
            std::cout << "Not jolly" << std::endl;
            return 0;
        }
    }
    std::cout << "Jolly" << std::endl;
    return 0;
}