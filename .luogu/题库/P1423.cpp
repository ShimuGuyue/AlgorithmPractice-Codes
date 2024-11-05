#include <iostream>

int main(void)
{
    double s;
    std::cin >> s;
    double len(2);
    int step(0);
    while (s > 0)
    {
        s -= len;
        ++step;
        len *= 0.98;
    }
    std::cout << step << std::endl;
    return 0;
}