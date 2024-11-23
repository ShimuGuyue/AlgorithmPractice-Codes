#include <iostream>
#include <vector>

bool Check(std::vector<int>& as, int x, int k);
int Binary_Search(std::vector<int>& as, int x, int l, int r);

int main(void)
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> ls(n);
    int max(0);
    for (int i(0); i < n; ++i)
    {
        std::cin >> ls[i];
        max = std::max(max, ls[i]);
    }
    std::cout << Binary_Search(ls, k, 1, max) << std::endl;
    return 0;
}

int Binary_Search(std::vector<int>& as, int x, int l, int r)
{
    while (l < r)
    {
        int mid((l + r) / 2);
        if (Check(as, mid, x))
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

bool Check(std::vector<int>& as, int x, int k)
{
    int sum(0);
    for (int a : as)
    {
        sum += a / x;
    }
    return sum >= k;
}