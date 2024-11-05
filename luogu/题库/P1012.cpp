#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::string> as(n);
    for (std::string& a : as)
    {
        std::cin >> a;
    }
    std::sort(as.begin(), as.end(),
    [](std::string a, std::string b)
    {
        return a + b > b + a;
    });
    std::string ans;
    for (std::string a : as)
    {
        ans += a;
    }
    std::cout << ans << std::endl;
    return 0;
}