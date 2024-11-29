#include <iostream>
#include <vector>

bool Check(std::vector<int>&vi, int x, int k);
int Binary_Search(std::vector<int>&vi, int l, int r, int k);

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    int l(0), r(0);
    std::vector<int> as(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i];
        l = std::max(l, as[i]);
        r += as[i];
    }
    int ans(Binary_Search(as, l, r, m));
    std::cout << ans << std::endl;
    return 0;
}

bool Check(std::vector<int>&vi, int x, int k)
{
    int sum(0);
    int count(0);
    for (int i : vi)
    {
        if (sum + i <= x)
        {
            sum += i;
        }
        else 
        {
            sum = i;
            ++count;
        }
    }
    if (sum)
        ++count;
    return count <= k;
}

int Binary_Search(std::vector<int>&vi, int l, int r, int k)
{
    while (l < r)
    {
        int mid((l + r) / 2);
        if (Check(vi, mid, k))
            r = mid;
        else
            l = mid + 1;   
    }
    return r; 
}