#include <iostream>
#include <vector>
#include <map>

struct Ship
{
    int t;
    std::vector<int> nationalitys;
};


int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Ship> ships(n);
    for (int i(0); i < n; ++i)
    {
        int k;
        std::cin >> ships[i].t >> k;
        for (int j(0); j < k; ++j)
        {
            int nationality;
            std::cin >> nationality;
            ships[i].nationalitys.push_back(nationality);
        }
    }

    int l(0);
    std::map<int, int> sum_nationalitys;
    for (int r(0); r < n; ++r)
    {
        while (ships[l].t <= ships[r].t - 86400)
        {
            for (int nationality : ships[l].nationalitys)
            {
                --sum_nationalitys[nationality];
                if (sum_nationalitys[nationality] == 0)
                    sum_nationalitys.erase(nationality);
            }
            ++l;
        }
        for (int nationality : ships[r].nationalitys)
        {
            ++sum_nationalitys[nationality];
        }
        std::cout << sum_nationalitys.size() << std::endl;
    }

    return 0;
}