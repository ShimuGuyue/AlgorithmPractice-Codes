#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i(0); i < n; ++i)
    {
        nums[i] = i + 1;
    }
    do
    {
        for (int i(0); i < n; ++i)
        {
            std::cout << std::setw(5) << nums[i];
        }
        std::cout << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));
    return 0;
}