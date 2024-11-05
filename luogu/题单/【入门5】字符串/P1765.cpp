#include <iostream>

int main(void)
{
    std::string s;
    std::getline(std::cin, s);
    int ans(0);
    for (char c : s)
    {
        if (c == ' ' || c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' || c == 't' || c == 'w')
            ans += 1;
        else if (c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' || c == 'u' || c == 'x')
            ans += 2;
        else if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' || c == 'v' || c == 'y')
            ans += 3;
        else if (c == 's' || c == 'z')
            ans += 4;
    }
    std::cout << ans << std::endl;
    return 0;
}