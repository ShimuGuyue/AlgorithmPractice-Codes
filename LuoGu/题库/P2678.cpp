/*
 *  参考教程：
 *  https://www.bilibili.com/video/BV1tT411L7qn/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
**/

#include <iostream>
#include <vector>

int Check(std::vector<int>& as, int k);
int Binary_Search(std::vector<int>& as, int l, int r, int m);

int main(void)
{
    int l, n, m;
    std::cin >> l >> n >> m;
    std::vector<int> as(n + 2);
    for (int i(1); i <= n; ++i)
    {
        std::cin >> as[i];
    }
    as[n + 1] = l;
    std::vector<int> lens(n + 1);
    for (int i(0); i <= n; ++i)
    {
        lens[i] = as[i + 1] - as[i];
    }

    int ans;
    if (n == m)
        ans = l;
    else
        ans = Binary_Search(lens, 1, l / (n - m), m);
    std::cout << ans << std::endl;
    return 0;
}

int Check(std::vector<int>& as, int k)
{
    int n(as.size());
    int ans(0);
    for (int i(0); i < n; ++i)
    {
        int temp(as[i]);
        while(temp < k && i < n)
        {
            ++i;
            temp += as[i];
            ++ans;
        }
    }
    return ans;
}

int Binary_Search(std::vector<int>& as, int l, int r, int m)
{
    while (l <= r)
    {
        int mid((l + r) / 2);
        int k(Check(as, mid));
        if (k <= m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}