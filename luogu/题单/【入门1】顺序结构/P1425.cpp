#include <iostream>

int main(void)
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int h(c - a);
    int m(d - b);
    if (m == 60)
    {
        m = 0;
        ++h;
    }
    if (m < 0)
    {
        m += 60;
        --h;
    }
    std::cout << h << " " << m << std::endl;
    return 0;
}