#include <iostream>

int Factorial(int x);

int main(void)
{
    int n;
    std::cin >> n;
    int ans(Factorial(n));
    std::cout << ans << std::endl;
    return 0;
}

int Factorial(int x)
{
    if (x == 1)
        return x;
    return x * Factorial(x - 1);
}