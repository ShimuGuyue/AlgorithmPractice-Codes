#include <iostream>
#include <cmath>

int main(void)
{
    int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << "I love Luogu!" << std::endl;
    }
    else if (n == 2)
    {
        std::cout << 6 << " " << 4 << std::endl;
    }
    else if (n == 3)
    {
        std::cout << 3 << std::endl;
        std::cout << 12 << std::endl;
        std::cout << 2 << std::endl;
    }
    else if (n == 4)
    {
        std::cout << 166.667 << std::endl;
    }
    else if (n == 5)
    {
        std::cout << 15 << std::endl;
    }
    else if (n == 6)
    {
        std::cout << sqrt(6 * 6 + 9 * 9) << std::endl;
    }
    else if (n == 7)
    {
        std::cout << 110 << std::endl;
        std::cout << 90 << std::endl;
        std::cout << 0 << std::endl;
    }
    else if (n == 8)
    {
        double PI(3.141593);
        double r(5);
        std::cout << 2 * PI * r << std::endl;
        std::cout << PI * r * r << std::endl;
        std::cout << PI * r * r * r * 4 / 3 << std::endl;
    }
    else if (n == 9)
    {
        std::cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2 << std::endl; 
    }
    else if (n == 10)
    {
        // x + 30 * n == 30 * 8  * v    // 20 * n == (240 - 10 * #) * v     // 240 - 10 * # == 50 * # - 300  
        // x + 6  * n == 6  * 10 * v    // 4  * n == (10 * # - 60)  * v     //       60 * # == 540
        // x + 10 * n == 10 * #  * v    // 20 * n == (50 * # - 300) * v     //            # == 9
        std::cout << 9 << std::endl;
    }
    else if (n == 11)
    {
        std::cout << 100.0 / (8 - 5) << std::endl;
    }
    else if (n == 12)
    {
        std::cout << 13 << std::endl;
        std::cout << "R" << std::endl;
    }
    else if (n == 13)
    {
        double PI(3.141593);
        double r1(4);
        double r2(10);
        double v(PI * r1 * r1 * r1 * 4 / 3 + PI * r2 * r2 * r2 * 4 / 3);
        int ans(pow(v, 1.0 / 3));
        std::cout << ans << std::endl;
    }
    else if (n == 14)
    {
        std::cout << 50 << std::endl;
    }
    return 0;
}