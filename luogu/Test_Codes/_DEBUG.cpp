#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> as(10);
    for (int i(0); i < 10; ++i)
    {
        std::cin >> as[i];
    }
    std::sort(as.rbegin(), as.rend());
    for (int i(0); i < 10; ++i)
    {
        std::cout << as[i] << " ";
    }
    return 0;
}