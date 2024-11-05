#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    if (n % 4)
        std::cout << 0 << std::endl;
    else
        if (n % 100)
            std::cout << 1 << std::endl;
        else
            if (n % 400)
                std::cout << 0 << std::endl;
            else
                std::cout << 1 << std::endl;
    return 0;
}