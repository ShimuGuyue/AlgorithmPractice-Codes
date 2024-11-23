#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, h, k;
    std::cin >> n >> h >> k;
    std::vector<int64_t> costs(n);
    for (int i(0); i < n; ++i)
    {
        int64_t HP, DAM;
        std::cin >> HP >> DAM;
        int64_t cost((HP - 1) / 4 * 3);
        if (HP % 4 == 1)
            cost += 0;
        else if (HP % 4 == 2)
            cost += 0;
        else if (HP % 4 == 3)
            cost += 1;
        else if (HP % 4 == 0)
            cost += 2;
        cost *= DAM;
        costs[i] = cost;
    }
    std::sort(costs.begin(), costs.end());
    std::vector<int64_t> costs_Sum(costs);
    for (int i(1); i < n; ++i)
    {
        costs_Sum[i] += costs_Sum[i-1];
    }

    int q;
    std::cin >> q;
    while (q--)
    {
        int64_t x;
        std::cin >> x;
        int64_t hp(h + x * k);
        int index;
        for (index = 0; index < n; ++index)
        {
            if (costs_Sum[index] >= hp)
                break;
        }
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*
怪物血量  1 2 3 4 | 5 6 7 8 | 9 10 11 12
扣血数    0 0 1 2 | 3 3 4 5 | 6  6  7  8  * 攻击力
扣血数 = ((怪物血量 - 1) / 4 * 3 + (怪物血量 % 4 == 1->0|2->0|3->1|0->2)) * 攻击力
*/