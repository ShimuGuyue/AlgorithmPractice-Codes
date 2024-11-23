#include <iostream>

int main(void)
{
    std::string s;
    std::getline(std::cin, s);
    int ans(0);
    for (char c : s)
    {
        if (c != ' ')
            ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}