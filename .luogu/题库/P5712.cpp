#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    if (n < 2)
        std::cout << "Today, I ate " << n << " apple.";
    else
        std::cout << "Today, I ate " << n << " apples.";
    return 0;
}