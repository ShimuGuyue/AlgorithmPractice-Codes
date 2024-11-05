#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

struct Loc
{
    double x;
    double y;
    double z;
};

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Loc> locs(n);
    for (Loc& loc : locs)
    {
        std::cin >> loc.x >> loc.y >> loc.z;
    }
    std::sort(locs.begin(), locs.end(),
    [](Loc a, Loc b)
    {
        return a.z < b.z;
    });
    double ans(0);
    for (int i(1); i < n; ++i)
    {
        double x1(locs[i - 1].x); double x2(locs[i].x); 
        double y1(locs[i - 1].y); double y2(locs[i].y); 
        double z1(locs[i - 1].z); double z2(locs[i].z); 
        ans += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    }
    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
    return 0;
}