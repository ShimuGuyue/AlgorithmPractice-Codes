#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    double n;
    std::cin >> n;
    double Fn((pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5));
    std::cout << std::fixed << std::setprecision(2) << Fn << std::endl;
    return 0;
}