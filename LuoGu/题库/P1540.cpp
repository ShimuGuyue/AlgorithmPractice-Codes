#include <iostream>
#include <vector>

int main(void)
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> dictionary;
    int ans(0);
    while (n--)
    {
        int a;
        std::cin >> a;
        bool is_find(false);
        for (int i(1); i <= m && static_cast<int>(dictionary.size()) - i >= 0; ++i)
        {
            if (dictionary[dictionary.size() - i] == a)
            {
                is_find = true;
                break;
            }
        }
        if (!is_find)
        {
            ++ans;
            dictionary.push_back(a);
        }
    } 
    std::cout << ans << std::endl;
    return 0;
}