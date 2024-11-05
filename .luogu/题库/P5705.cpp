#include <iostream>
int main(void)
{
    std::string s;
    std::cin >> s;
    for (int i(s.size() - 1); i >= 0; --i)
    {
        std::cout << s[i];
    }
    std::cout << std::endl;
    return 0;
}