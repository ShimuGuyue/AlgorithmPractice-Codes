#include <iostream>
#include <vector>

int64_t Check(std::vector<int>& as, int x);
int Binary_Search(std::vector<int>& as, int x, int l, int r);

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> hs(n);
    int max(0);
    for (int i(0); i < n; ++i)
    {
        std::cin >> hs[i];
        max = std::max(max, hs[i]);
    }
    int ans(Binary_Search(hs, m, 0, max));
    std::cout << ans << std::endl;
    return 0;
}

int Binary_Search(std::vector<int>& as, int x, int l, int r)
{
    while (l < r)
    {
        int mid((l + r + 1) / 2);
        if (Check(as, mid) >= x)
            l = mid;
        else // Check(as, mid) < x
            r = mid - 1;
    }
    return l;
}

int64_t Check(std::vector<int>& as, int x)
{
    int64_t ans(0);
    for (int a : as)
    {
        ans += std::max(0, a - x);
    }
    return ans;
}