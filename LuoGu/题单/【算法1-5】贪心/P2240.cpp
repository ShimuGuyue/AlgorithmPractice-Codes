#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Corn
{
    double m;
    double v;
};


int main(void)
{
    int n, t;
    std::cin >> n >> t;
    std::vector<Corn> corns(n);
    for (Corn& corn : corns)
    {
        std::cin >> corn.m >> corn.v;
    }
    std::sort(corns.begin(), corns.end(),
    [](Corn a, Corn b)
    {
        return a.v / a.m > b.v / b.m;
    });

    double ans(0);
    for (Corn corn : corns)
    {
        if (corn.m < t)
        {
            ans += corn.v;
            t -= corn.m;
        }
        else
        {
            ans += corn.v * t / corn.m;
            t = 0;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}