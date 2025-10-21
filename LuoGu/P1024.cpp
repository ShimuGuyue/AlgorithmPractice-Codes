#include <iostream>
#include <iomanip>

double F3(double a, double b, double c, double d, double x);

int main(void)
{
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (double i(-100); i <= 100; i += 0.01)
    {
        if (F3(a, b, c, d, i) * F3(a, b, c, d, i + 0.01) <= 0)
            std::cout << std::fixed << std::setprecision(2) << i + 0.01 << " ";
    }
    std::cout << std::endl;
    return 0;
}

double F3(double a, double b, double c, double d, double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}