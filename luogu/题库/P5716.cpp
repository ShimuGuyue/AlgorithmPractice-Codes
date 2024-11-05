#include <iostream>

int main(void)
{
    int y, m;
    std::cin >> y >> m;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        std::cout << 31 << std::endl;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        std::cout << 30 << std::endl;
    else
        if (y % 4)
            std::cout << 28 << std::endl;
        else
            if (y % 100)
                std::cout << 29 << std::endl;
            else
                if (y % 400)
                    std::cout << 28 << std::endl;
                else
                    std::cout << 29 << std::endl;
    return 0;
}