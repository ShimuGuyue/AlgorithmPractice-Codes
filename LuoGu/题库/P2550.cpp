#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n;
    std::cin >> n;
    std::map<int, int> flags;
    for (int i(0); i < 7; ++i)
    {
        int flag;
        std::cin >> flag;
        ++flags[flag];
    }
    std::vector<int> ans(7);
    while (n--)
    {
        int count(0);
        for (int i(0); i < 7; ++i)
        {
            int num;
            std::cin >> num;
            if (flags[num])
                ++count;
        }
        if (count)
            ++ans[7 - count];
    }
    for (int i : ans)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}