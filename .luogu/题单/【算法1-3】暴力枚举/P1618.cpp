#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> nums(10);
    for (int i(1); i < 10; ++i)
    {
        nums[i] = i;
    }
    bool ok(false);
    do
    {
        int x(nums[1] * 100 + nums[2] * 10 + nums[3]);
        int y(nums[4] * 100 + nums[5] * 10 + nums[6]);
        int z(nums[7] * 100 + nums[8] * 10 + nums[9]);
        if (x * b == y * a && x * c == z * a && y * c == z * b)
        {
            std::cout << x << " " << y << " " << z << std::endl;
            ok = true;
        }
    }
    while (next_permutation(nums.begin() + 1, nums.end()));
    if (!ok)
    {
        std::cout << "No!!!" << std::endl;
    }
    return 0;
}