#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

struct Loc
{
    double x;
    double y;
};

int n;
std::vector<Loc> locs;
double ans(INT_MAX);

void Dfs(double x, double y, double sum, std::vector<int> flags);

int main(void)
{
    std::cin >> n;
    locs = std::vector<Loc>(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> locs[i].x >> locs[i].y;
    }

    std::vector<int> flags(n);
    Dfs(0, 0, 0, flags);
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}

void Dfs(double x, double y, double sum, std::vector<int> flags)
{
    bool is_end(true);

    for (int i(0); i < n; ++i)
    {
        if (flags[i])
            continue;

        double len(sqrt(pow(x - locs[i].x, 2) + pow(y - locs[i].y, 2)));
        flags[i] = 1;
        Dfs(locs[i].x, locs[i].y, sum + len, flags);
        flags[i] = 0;

        is_end = false;
    }

    if (is_end)
        ans = std::min(ans, sum);
}