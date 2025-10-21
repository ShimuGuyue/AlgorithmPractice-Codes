#include <iostream>
#include <set>

int main(void)
{
    int n, m;
    std::cin >> n;
    std::multiset<int> nums;
    while (n--)
    {
        int a;
        std::cin >> a;
        nums.insert(a);
    }
    for (int ans : nums)
    {
        std::cout << ans << " ";
    }
    std::cout << std::endl;
    return 0;
}