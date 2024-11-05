#include <iostream>

int main(void)
{
    std::string a;
    std::string b;
    std::cin >> a;
    std::cin >> b;

    int flagA(1);
    int flagB(1);
    for (char c : a)
    {
        flagA = flagA * (c - 'A' + 1) % 47;
    }
    for (char c : b)
    {
        flagB = flagB * (c - 'A' + 1) % 47;
    }

    if (flagA == flagB)
        std::cout << "GO" << std::endl;
    else
        std::cout << "STAY" << std::endl;

    return 0;
}