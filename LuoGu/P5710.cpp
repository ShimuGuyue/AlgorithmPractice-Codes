#include <iostream>

int main(void)
{
    int count(0);
    int n;
    std::cin >> n;
    if (n % 2 == 0)
        ++count;
    if (4 < n && n <= 12)
        ++count;
    
    if (count == 2)
        std::cout << 1 << " ";
    else
        std::cout << 0 << " ";
    if (count)
        std::cout << 1 << " ";
    else
        std::cout << 0 << " ";
    if (count == 1)
        std::cout << 1 << " ";
    else
        std::cout << 0 << " ";
    if (count == 0)
        std::cout << 1 << " ";
    else
        std::cout << 0 << " ";
    return 0;
}