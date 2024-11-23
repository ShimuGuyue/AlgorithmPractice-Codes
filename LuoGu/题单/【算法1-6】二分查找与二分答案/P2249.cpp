#include <iostream>
#include <vector>

int Binary_Search(std::vector<int>& a, int x);

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> nums[i];
    }
    while (m--)
    {
        int q;
        std::cin >> q;
        std::cout << Binary_Search(nums, q) << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*有重复，查找第一次出现的位置*/
int Binary_Search(std::vector<int>& as, int x)
{
    int l(0), r(as.size()-1);
    while (l < r)
    {
        int mid((l + r) / 2);
        if (as[mid] < x)
            l = mid + 1;
        else // as[mid] > x
            r = mid;
    }
    if (as[l] != x)
        return -1;
   	while (l > 0 && as[l - 1] == x)
    {
        --l;
    }
    return l + 1;
}