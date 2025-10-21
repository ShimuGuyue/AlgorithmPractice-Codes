#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n, c;
    std::cin >> n >> c;
    std::map<int, int64_t> nums;
    while (n--)
    {
        int x;
        std::cin >> x;
        ++nums[x];
    }
    int64_t ans(0);
    std::map<int, int64_t> nums_copy(nums);
    for (std::pair<int, int64_t> ii : nums)
    {
        int b(ii.first);
        int a(b + c);
        ans += nums[b] * nums_copy[a];
    }
    std::cout << ans << std::endl;
    return 0;
}