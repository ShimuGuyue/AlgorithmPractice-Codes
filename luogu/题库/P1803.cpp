#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> times(n);
    for (std::pair<int, int>& time : times)
    {
        std::cin >> time.first >> time.second;
    }
    
    std::sort(times.begin(), times.end(),
    [](std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.second < b.second;
    });

    int ans(0);
    int flag(0);
    for (std::pair<int, int> time : times)
    {
        if (time.first >= flag)
        {
            ++ans;
            flag = time.second;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}