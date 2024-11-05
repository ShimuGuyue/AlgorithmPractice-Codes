#include <iostream>

int main(void)
{
    char c;
    std::cin >> c;
    std::cout << "  " << c << std::endl;
    std::cout << " " << c << c << c << std::endl;
    std::cout << c << c << c << c << c << std::endl;
    return 0;
}