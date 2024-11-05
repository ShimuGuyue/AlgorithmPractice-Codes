#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b)
        std::swap(a, b);
    if (a > c)
        std::swap(a, c);
    if (b > c)
        std::swap(b, c);

    if (a + b <= c)
    {
        std::cout << "Not triangle" << std::endl;
        return 0;
    }

    if (a * a + b * b > c * c)
        std::cout << "Acute triangle" << std::endl;
    else if (a * a + b * b == c * c)
        std::cout << "Right triangle" << std::endl;
    else if (a * a + b * b < c * c)
        std::cout << "Obtuse triangle" << std::endl;

    if (a == b || b == c)
        std::cout << "Isosceles triangle" << std::endl;
    if (a == b && a == c)
        std::cout << "Equilateral triangle" << std::endl;

    return 0;
}