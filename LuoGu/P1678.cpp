#include <iostream>
#include <vector>
#include <algorithm>

int Binary_Search(std::vector<int64_t>& as, int x);

int main(void)
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int64_t> schools(m);
    std::vector<int64_t> students(n);
    for (int i(0); i < m; ++i)
    {
        std::cin >> schools[i];
    }
    for (int i(0); i < n; ++i)
    {
        std::cin >> students[i];
    }
    std::sort(schools.begin(), schools.end());
    int64_t ans(0);
    for (int i(0); i < n; ++i)
    {
        int l(Binary_Search(schools, students[i]));
        int r(l + 1);
        if (l >= 0)
            ans += std::min(abs(schools[l] - students[i]), abs(schools[r] - students[i]));
        else
            ans += abs(schools[r] - students[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}

int Binary_Search(std::vector<int64_t>& as, int x)
{
    int l(0), r(as.size()-1);
    while (l < r)
    {
        int mid((l + r) / 2);
        if (as[mid] < x)
            l = mid + 1;
        else // as[mid] >= x
            r = mid;
    }
    return l - 1;
}