#include <iostream>

int main(void)
{
    int x;
    std::cin >> x;
    if (x >= 100 || x < 10)
        std::cout << "No" << std::endl;
    else if (x / 10 == x % 10)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}