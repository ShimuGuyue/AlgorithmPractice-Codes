#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    int m;
    std::cin >> n;
    std::cin >> m;
    std::vector<int> as(n);
    for (int& a : as)
    {
        std::cin >> a;
    }
    while (m--)
    {
        std::next_permutation(as.begin(), as.end());
    }
    for (int a : as)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}