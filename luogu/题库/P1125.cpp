#include <iostream>
#include <map>

bool is_prime(int n);

int main(void)
{
    std::string s;
    std::cin >> s;
    std::map<char, int> counts;
    for (char c : s)
    {
        ++counts[c];
    }
    int max(0);
    int min(100);
    for (std::pair<char, int> ci : counts)
    {
        max = std::max(max, ci.second);
        min = std::min(min, ci.second);
    }
    int ans(max - min);
    if (is_prime(ans))
    {
        std::cout << "Lucky Word" << std::endl;
        std::cout << ans << std::endl;
    }
    else
    {
        std::cout << "No Answer" << std::endl;
        std::cout << 0 << std::endl;
    }
    return 0;
}

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i(2); i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}