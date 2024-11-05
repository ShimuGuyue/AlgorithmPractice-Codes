#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int sum(0);
    bool one(false);
    do
    {
        int a;
        std::cin >> a;
        for (int i(1); i <= a; ++i)
        {
            ++sum;
            if (one)
                std::cout << 1;
            else
                std::cout << 0;
            if (sum % n == 0)
                std::cout << std::endl;
        }
        one = !one;
        
    } while (sum < n * n);
    return 0;
}