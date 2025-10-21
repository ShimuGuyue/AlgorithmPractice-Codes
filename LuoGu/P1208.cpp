#include <iostream>
#include <vector>
#include <algorithm>

struct Milk
{
    int price;
    int yield;
};

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Milk> milks(m);
    for (int i(0); i < m; ++i)
    {
        std::cin >> milks[i].price >> milks[i].yield;
    }

    std::sort(milks.begin(), milks.end(),
    [](Milk a, Milk b)
    {
        return a.price < b.price;
    });

    int ans(0);
    for (int i(0); i < m; ++i)
    {
        if (n <= milks[i].yield)
        {
            ans += n * milks[i].price;
            break;
        }
        else
        {
            ans += milks[i].yield * milks[i].price;
            n -= milks[i].yield;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}