#include <iostream>
#include <iomanip>

int main(void)
{
    double t;
    int n;
    std::cin >> t >> n;
    std::cout << std::fixed << std::setprecision(3) << t / n << std::endl;
    std::cout << n * 2 << std::endl;
    return 0;
}