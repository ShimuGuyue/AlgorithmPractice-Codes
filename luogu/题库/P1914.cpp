#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (char& c : s)
    {
        c = (c - 'a' + n) % 26 + 'a';
    }
    std::cout << s << std::endl;
    return 0;
}