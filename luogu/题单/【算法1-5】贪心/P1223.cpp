#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Time
{
    double time;
    int index;
};


int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Time> times(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> times[i].time;
        times[i].index = i + 1;
    }
    std::sort(times.begin(), times.end(),
    [](Time a, Time b)
    {
        return a.time < b.time;
    });

    double ans(0);
    for (int i(0); i < n; ++i)
    {
        ans += times[i].time * (n - i - 1);
        std::cout << times[i].index << " ";
    }
    std::cout << std::endl;
    ans /= n;
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;

    return 0;
}