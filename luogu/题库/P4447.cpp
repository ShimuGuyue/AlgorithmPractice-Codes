#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n;
    std::cin >> n;
    std::map<int, int> strengths;
    while (n--)
    {
        int a;
        std::cin >> a;
        ++strengths[a];
    }

    int ans(100000);
    while (!strengths.empty())
    {
        int sum(0); 
        std::vector<int> erases;
        for (std::map<int, int>::iterator ii(strengths.begin()); ii != strengths.end(); /*++ii*/)
        {
            ++sum;
            --ii->second;
            if (ii->second == 0)
                erases.push_back(ii->first);

            std::map<int, int>::iterator jj(ii);
            ++ii;
            if (ii == strengths.end())
                break;
            if (jj->second + 1 > ii->second)
                break;
            if (jj->first + 1 != ii->first)
                break;
        }
        for (int e : erases)
        {
            strengths.erase(e);
        }
        ans = std::min(ans, sum);
    }
    std::cout << ans << std::endl;
    return 0;
}