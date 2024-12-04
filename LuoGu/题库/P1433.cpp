/**
 * 参考教程：
 * https://www.bilibili.com/video/BV1er421s7rW/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>

struct Loc
{
    double x;
    double y;
};

int n;
std::vector<Loc> locs;
std::vector<int> flags;
std::vector<std::vector<double>> dp;

double Dfs(int now, int path, double sum, int count);

int main(void)
{
    std::cin >> n;
    locs = std::vector<Loc>(n + 1);
    for (int i(1); i <= n; ++i)
    {
        std::cin >> locs[i].x >> locs[i].y;
    }

    flags = std::vector<int>(n + 1);
    dp = std::vector<std::vector<double>> (n + 1, std::vector<double>((1 << n) + 1));

    double ans(Dfs(0, 0, 0, 0));
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}

double Dfs(int now, int path, double sum, int count)
{
    if (count == n)
        return sum;
    if (dp[now][path])
        return sum + dp[now][path];

    double ans(INT_MAX);

    for (int i(1); i <= n; ++i)
    {
        if (flags[i])
            continue;

        double x1(locs[now].x), x2 = locs[i].x;
        double y1(locs[now].y), y2 = locs[i].y;
        double len(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

        flags[i] = 1;
        ans = std::min(ans, Dfs(i, path | (1 << i), sum + len, count + 1));
        flags[i] = 0;
    }

    dp[now][path] = ans - sum;
    return ans;
}