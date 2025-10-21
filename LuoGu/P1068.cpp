#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> peoples(n); // { k, s}
    for (std::pair<int, int>& ii : peoples)
    {
        std::cin >> ii.first >> ii.second;
    } 
    m *= 1.5;
    std::sort(peoples.begin(), peoples.end(),
    [](std::pair<int, int> a, std::pair<int, int> b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });
    int flag(peoples[m - 1].second);
    int count(0);
    for (int i(0); i < n; ++i)
    {
        if (peoples[i].second >= flag)
            ++count;
    }
    std::cout << flag << " " << count << std::endl;
    for (int i(0); i < count; ++i)
    {
        std::cout << peoples[i].first << " " << peoples[i].second << std::endl;
    }
    return 0;
}