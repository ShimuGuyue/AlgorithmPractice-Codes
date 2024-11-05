#include <iostream>

int main(void)
{
    double m, h;
    std::cin >> m >> h;
    double BMI(m / h / h);
    if (BMI < 18.5)
        std::cout << "Underweight" << std::endl;
    else if (BMI < 24)
        std::cout << "Normal" << std::endl;
    else
    {
        std::cout << BMI << std::endl;
        std::cout << "Overweight" << std::endl;
    }
    return 0;
}