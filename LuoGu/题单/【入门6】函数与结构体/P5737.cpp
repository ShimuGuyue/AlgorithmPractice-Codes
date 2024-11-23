#include <iostream>
#include <vector>

bool is_leap(int x);

int main(void)
{
    int x, y;
    std::cin >> x >> y;
    int ans(0);
    std::vector<int> anss;
    for (int i(x); i <= y; ++i)
    {
        if (is_leap(i))
        {
            ++ans;
            anss.push_back(i);
        }
    }
    std::cout << ans << std::endl;
    for (int i : anss)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

bool is_leap(int x)
{
    if (x % 4 == 0)
        if (x % 100 == 0)
            if (x % 400 == 0)
                return true;
            else
                return false;
        else
            return true;
    else
        return false;
}