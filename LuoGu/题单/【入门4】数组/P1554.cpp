#include <iostream>
#include <vector>

int main(void)
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> ans(10);
    for (int i(m); i <= n; ++i)
    {
        int temp(i);
        while (temp)
        {
            ++ans[temp % 10];
            temp /=10;
        }
    }
    for (int i : ans)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}