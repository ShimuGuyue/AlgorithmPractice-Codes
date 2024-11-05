#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int local(n * 5);
    int luogu(n * 3 + 11);
    if (local < luogu)
        std::cout << "Local" << std::endl;
    else
        std::cout << "Luogu" << std::endl;
    return 0;
}